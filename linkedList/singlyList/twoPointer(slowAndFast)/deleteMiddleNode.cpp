#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int data) {
        val = data;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // Function to delete middle node of linked list
    Node* deleteMiddle(Node* head) {
        
        // edge case: single node
        if(!head || !head->next) {
            return nullptr;
        }

        Node* slow = head;
        Node* fast = head;
        Node* prev = nullptr;

        // find middle and track previous node
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // delete middle node
        prev->next = slow->next;
        delete slow;

        return head;
    }
};

int main() {
    return 0;
}