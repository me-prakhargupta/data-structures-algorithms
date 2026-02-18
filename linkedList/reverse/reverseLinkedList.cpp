#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

class LinkedList {
public:

    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insertNode(int val) {
        Node* newNode = new Node(val);

        if(head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void display() {
        if(head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        while(temp != nullptr) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }

        cout << "NULL";
    }

    void reverse() {
        Node* curr = head;
        Node* prev = nullptr;

        while(curr != nullptr) {
            Node* next = curr->next; // preserve next pointer
            curr->next = prev; // reverse link
            prev = curr; // move prev
            curr = next; // move curr
        }
    }

    Node* reverseRecursive(Node* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        Node* newHead = reverseRecursive(head->next);

        head->next->next = head;
        head->next = nullptr;
    }

    // Function to reverse first K nodes
    Node* reverseKNode(int k) {
        if(head == nullptr || k == 1) {
            return;
        }

        Node* curr = head;
        Node* prev = nullptr;
        Node* nextNode = nullptr;
        int count = 0;

        while(curr != nullptr && count < k) {
            nextNode = curr->next;
            curr->next = prev;
            curr = nextNode;
            prev = curr;
            count++;
        }

        head->next = curr;
    }
};

int main() {
    LinkedList ll;
    ll.insertNode(1);
    ll.insertNode(2);
    ll.insertNode(3);
    ll.display();
    return 0;
}