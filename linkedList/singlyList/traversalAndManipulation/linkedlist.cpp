#include<iostream>
using namespace std;

// Class to implement node in singly linked list
class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        this->next = nullptr;
    }
};

// Class to implement Singly linked list
class LinkedList {
public:
    Node* head;

    // Default Constructor
    LinkedList() {
        head = nullptr;
    }

    // Funtion to insert a node at the head of linked list
    // Time Complexity - O(1)
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to insert a node at the end of linked list
    // Time Complexity - O(n)
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
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

    // Function to delete head node in linked list
    // Time Complexity - O(1)
    void deleteAtHead() {
        if(head == nullptr) return;

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Function to delete tail node in linked list
    // Time Complexity - O(n)
    void deleteAtTail() {
        if(head == nullptr) return;
        
        Node* temp = head;
        while(temp->next->next != nullptr) {
            temp = temp->next;
        }

        Node* delNode = temp->next->next;
        temp->next = nullptr;
        delete delNode;
    }

    // Function to delete node by value in linked list
    void deleteByValue(int value) {
        if(head == nullptr) return;

        if(head->value == value) {
            deleteAtHead();
            return;
        }

        Node* temp = head;
        while(temp->next != nullptr && temp->next->value != value) {
            temp = temp->next;
        }

        // Check if node exist
        if(temp->next == nullptr) return;
        Node* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
    }

    // Function to display linked list
    // Time Complexity - O(n);
    void display() {
        // Check for empty list
        if(head == nullptr) {
            cout << "Empty List" << endl;
            return;
        }

        //Traverse list
        Node* temp = head;
        while(temp != nullptr) {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Function to calculate the length of linked list
    void findLength() {
        int len = 0;
        Node* temp = head;

        while(temp != nullptr) {
            len++;
            temp = temp->next;
        }

        cout << "Length of linked list is: " << len << endl;
    }

    // Function to search element in linked list
    void searchElement(int value) {
        if(head == nullptr) {
            cout << "Linked List is empty" << endl;
            return;
        }

        Node* temp = head;
        int position = 1;

        while(temp != nullptr) {
            if(temp->value == value) {
                cout << "Element is found at position: " << position << endl;
            }

            temp = temp->next;
            position++;
        }

        cout << "Element is not found in linked list" << endl;
    }

    // Function to insert node at given position 
    void insertAtPos(int value, int pos) {
        if(pos == 1) {
            insertAtHead(value);
            return;
        }

        int count = 0;
        Node* temp = head;

        // Reach (pos - 1)th node
        while(temp != nullptr && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        // If position is invalid
        if(temp == nullptr) {
            cout << "Invalid position" << endl;
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }
};

int main() {
    LinkedList ll;
    ll.insertAtHead(10);
    ll.insertAtHead(9);
    ll.insertAtTail(12);
    ll.searchElement(14);
    // ll.findLength();
    return 0;
}