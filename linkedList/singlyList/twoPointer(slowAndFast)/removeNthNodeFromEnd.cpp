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

    // Brute force: Two pass
    // Optimal Approach: Runs in O(n) time, and O(1) space;
    Node* removeNthNodeFromEnd(Node* head, int n) {
        // dummy node handles edge case (deleting head)
        // Node dammy(0, head) => for leetcode
        Node dammy(0);
        Node* slow = &dammy;
        Node* fast = &dammy;

        // move fast n steps ahead
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // move both until fast reaches last node
        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        // delete node
        Node* del = slow->next;
        slow->next = del->next;
        delete del;

        return head;
    }
};

int main() {
    return 0;
}