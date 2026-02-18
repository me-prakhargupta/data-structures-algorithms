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

    // This function checks whether a linked list has a cycle.
    bool detectCycle(Node* head) {
        Node* slow = head;
        Node* fast = head;

        while(fast && fast->next) {
            // The slow pointer moves one step at a time,
            slow = slow->next;

            // while the fast pointer moves two steps at a time.
            fast = fast->next->next;

            // If a cycle exists, both pointers will eventually 
            // meet at the same node
            if(slow == fast) {
                return true;
            }
        }

        return false;
    }

    // Runs in O(n) time and O(1) extra space.
};

int main() {
    return 0;
}