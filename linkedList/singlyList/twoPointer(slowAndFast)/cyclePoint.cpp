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

    Node* cycleStartingPoint(Node* head) {
        Node* slow = head;
        Node* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next;

            if(slow == fast) break;
        }

        if(!fast && !fast->next) return nullptr;

        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }

    // Runs in O(n) time and O(1) extra space.
};

int main() {
    return 0;
}