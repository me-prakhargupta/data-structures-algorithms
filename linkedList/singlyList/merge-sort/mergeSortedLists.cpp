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

        // Approach: Iterative merge using a dummy node
        Node* mergeLists(Node* head1, Node* head2) {
            
        // Use a dummy node to simplify handling of the head of the merged list.
        Node dummy(0);
        
        // Maintain a 'tail' pointer to build the result list.
        Node* tail = &dummy;
        
        // Compare current nodes of both lists and attach the smaller one to tail.
        // Continue until one list becomes empty.
        // Move the corresponding pointer forward and update tail.
        while(head1 && head2) {
            if(head1->val < head2->val) {
                tail->next = head1;
                head1 = head1->next;
            } else {
                tail->next = head2;
                head2 = head2->next;
            }
            
            tail = tail->next;
        }
        
        // Finally, attach the remaining nodes of the non-empty list.
        if(head1) tail->next = head1;
        else tail->next = head2;
        
        return dummy.next;
    }

    // Time Complexity: O(n + m)
    // Space Complexity: O(1) (in-place merge, no extra space used)
};

int main() {
    return 0;
}