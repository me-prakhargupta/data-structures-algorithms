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

    // Brute-force: Find length, then locate (length - k + 1)th node
    Node* nthNodeFromEnd(int k) {
        Node* temp =  head;
        int length = 0;

        // Traverse the linked list to calculate its total length.
        while(temp) {
            length++;
            temp = temp->next;
        }

        // Edge case: k is greater than length
        if(k > length) return nullptr;

        // Compute the position of the required node from the beginning:
        // (length - k + 1).
        int nodeIndexToReturn = length - k + 1;

        Node* curr = head;
        int i = 1;

        // Traverse again up to that position and return the node.
        while(i < nodeIndexToReturn) {
            i++;
            curr = curr->next;
        }

        return curr;
    }
    
    // Time Complexity: O(N) + O(N) = O(N)
    // Space Complexity: O(1)
};

int main() {
    return 0;
}