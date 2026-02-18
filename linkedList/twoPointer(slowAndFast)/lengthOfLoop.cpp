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

        // This function calculates the length of a cycle in a linked list.
        int lengthOfLoop(Node* head) {
        Node* slow = head;
        Node* fast = head;

        // It first detects a cycle using slow and fast pointers.
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            // Once a meeting point is found,
            if(slow == fast) {
                slow = slow->next;
                break;
            }
        }

        if(!fast || !fast->next) {
            return 0;
        }

        int count = 1;

        // one pointer is moved until it reaches the same node again
        while(slow != fast) {
            slow = slow->next;

            // while counting the number of steps,
            count++;
        }

        // which gives the cycle length.
        return count;
    }

    // Runs in O(n) time and O(1) extra space.
};

int main() {
    return 0;
}