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

        Node* curr = head;
        while(curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = newNode;

    }

    void display() {
        if(head == nullptr) {
            cout << "Empty List" << endl;
            return;
        }

        Node* curr = head;
        while(curr != nullptr) {
            cout << curr->val << " -> ";
            curr = curr->next;
        }

        cout << "NULL" << endl;
    }

    Node* reverseKGroups(Node* head, int k) {
        int count = 0;
        Node* temp = head;

        // Check if at least k nodes exist
        while(count < k) {
            if(temp == nullptr) return head;
            temp = temp->next;
            count++;
        }

        // Recursively process remaining list
        Node* prev = reverseKGroups(temp, k);

        // Reverse current k nodes
        Node* next = nullptr;
        Node* curr = head; // reset curr
        count = 0; // reset count

        while(count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // prev is the new head of this block
        return prev;
    }
};

int main() {
    LinkedList ll;
    ll.insertNode(1);
    ll.insertNode(2);
    ll.insertNode(3);
    ll.insertNode(4);
    ll.insertNode(5);
    ll.display();
    return 0;
}