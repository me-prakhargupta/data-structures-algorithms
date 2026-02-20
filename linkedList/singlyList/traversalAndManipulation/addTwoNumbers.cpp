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

    Node* addTwoNumbers(Node* head1, Node* head2) {
        // avoid edge cases (like empty list or first insertion)
        Node dummy(0);

        // tail pointer is used to build the result list
        // always points to the last node of result list
        Node* tail = &dummy;

        // stores carry during addition (like we do manually)
        int carry = 0;

        // even if lists ends, we still process leftover carry
        while(head1 || head2 || carry) {
            // start with carry (from previous step)
            int sum = carry;

            if(head1) {
                sum += head1->val;
                head1 = head1->next;
            }

            if(head2) {
                sum += head2->val;
                head2 = head2->next;
            }

            // now process the sum
            carry = sum / 10;

            // create a new node with last digit
            tail->next = new Node(sum % 10);

            // move tail forward, now it points to the newly added node
            tail = tail->next;
        }

        // return actual head (skip dummy node)
        return dummy.next;
    }
};

int main() {
    return 0;
}