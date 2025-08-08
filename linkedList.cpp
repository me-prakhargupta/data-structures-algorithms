#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = nullptr;
    }

    void insertAtLast(int value) {
        Node* newNode = new Node(value);

        if(head == nullptr) {
            head = newNode;
            return;
        } else {
            Node* temp = head;
            while(temp != nullptr) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    void insertAtBegining(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void deleteByValue(int value) {
        if(head == nullptr) {
            return;
        }
        if(head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while(temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if(temp->next == nullptr) {
            cout << "Value not found." << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    void display() {
        Node* temp = head;
        while(temp != nullptr) {
            cout << temp->data << "->";
        }
        cout << "NULL" << endl;
    }
};

int main() {
    return 0;
}