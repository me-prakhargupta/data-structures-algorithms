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

    Node* reverseAlternateKNodes(Node* head, int k) {
        if(head == nullptr) return head;

        Node* curr = head;
        Node* next = nullptr;
        Node* prev = nullptr;
        int count = 0;

        // Reverse the first k nodes of the linked list
        while(count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Now head points to the kth node. 
  	    // So change next of head to (k+1)th node

        if(head != nullptr) {
            head->next = curr;
        }

        // Skip the next k nodes
        count = 0;
        while(curr != nullptr && count < k - 1) {
            curr = curr->next;
            count++;
        }

        // Recursively call for the list
        // starting from curr->next;
        if(curr != nullptr) {
            curr->next = reverseAlternateKNodes(curr->next, k);
        }

        return prev;
    }
};

int main() {
    return 0;
}