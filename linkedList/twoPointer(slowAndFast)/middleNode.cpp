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

    // This function finds the middle node of a singly linked list.
    Node* middleNode(Node* head) {
        Node* slow = head;
        Node* fast = head;

        while(fast && fast->next) {
            // The slow pointer moves one step at a time,
            slow = slow->next;

            // while the fast pointer moves two steps at a time.
            fast = fast->next->next;
        }
        // When the fast pointer reaches the end,
        // the slow pointer will be at the middle of the list
        return slow;
    }

    // Runs in O(n) time and O(1) extra space.
};

int main() {
    return 0;
}