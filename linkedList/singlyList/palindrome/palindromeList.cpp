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

    // Find middle of linked list using slow-fast pointer
    Node* middleOfNode(Node* head) {
        Node* slow = head;
        Node* fast = head;

        // fast moves 2 steps, slow moves 1 step
        // when fast reaches end, slow is at middle
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Reverse a linked list (iterative approach)
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = nullptr;
        Node* next;

        while(curr) {
            next = curr->next; // store next node
            curr->next = prev; // reverse link
            prev = curr;       // move prev forward
            curr = next;       // move curr forward
        }

        return prev; // new head of reversed list
    }

    bool isPalindrome(Node* head) {
        // edge case: empty or single node is palindrome
        if(!head || !head->next) return true;;

        Node* curr = head;

        // find middle of list
        Node* middleNode = middleOfNode(head);

        // reverse second half
        Node* reverseHead = reverse(middleNode);

        // compare both halves
        while(reverseHead) {
            if(curr->val != reverseHead->val) {
                return false;
            }

            curr = curr->next;
            reverseHead = reverseHead->next;
        }

        return true; // palindrome
    }
};

int main() {
    return 0;
}