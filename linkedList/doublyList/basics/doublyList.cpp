#include<iostream>
#include<unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) {
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insertHead(int val) {
        Node* newHead = new Node(val);

        if(!head) {
            head = newHead;
            return;
        }

        newHead->next = head;
        head->prev = newHead;
        head = newHead;
    }

    void insertTail(int val) {
        if(!head) {
            head = new Node(val);
            return;
        }

        Node* temp = head;
        while(temp->next) {
            temp = temp->next;
        }

        Node* newNode = new Node(val);
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteHead() {
        if(!head) {
            cout << "Empty list" << endl;
            return;
        }

        Node* nodeToDelete = head;
        head = head->next;

        if(head) {
            head->prev = nullptr;
        }

        delete nodeToDelete;
    }

    // Rule for reversing DLL:
    // Swap next and prev for every node
    // Update head at the end
    
    void reverse() {
        if(!head) {
            cout << "Empty list" << endl;
            return;
        }

        Node* temp = head;
        Node* newHead = nullptr;
        while(temp) {
            Node* next = temp->next;

            temp->next = temp->prev;
            temp->prev = next;

            newHead = temp; // track last processed node
            temp = next;
        }

        head = newHead;
    }

    void display() {
        Node* temp = head;
        while(temp) {
            cout << temp->val << " <=> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList ll;

    ll.insertHead(1);
    ll.insertTail(2);
    ll.insertTail(1);
    ll.insertTail(1);
    ll.insertTail(2);
    ll.insertTail(4);
    ll.insertTail(4);
    
    ll.display();

    // ll.deleteHead();
    // ll.display();
    // ll.deleteHead();
    // ll.reverse();
    ll.display();

    return 0;
}