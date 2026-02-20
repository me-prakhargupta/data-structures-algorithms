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

    // Fun to find to middle node of list
    Node* findMiddle(Node* head) {
        Node* slow = head;
        Node* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    Node* merge(Node* left, Node* right) {
        Node dammy(0);
        Node* tail = &dammy;

        while(left && right) {
            if(left->val < right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }

            tail = tail->next;
        }

        tail->next = left ? left : right;

        return dammy.next;
    }

    // Function to sort linked list (merge sort)
    Node* sortList(Node* head) {

        if(!head || !head->next) return nullptr;
        
        // Find the middle of linked list (slow-fast pointer)
        Node* mid = findMiddle(head);

        // Split into 2 halves
        Node* right = mid->next;
        mid->next = nullptr;
        
        // Recursively sort two halves     
        Node* left = sortList(head);
        right = sortList(right);

        // Merge sorted lists
        return merge(left, right);
    }
};

int main() {
    return 0;
}