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

    int solve(Node* head) {
        // base case: reached end
        if(!head) {
            return 0;
        }

        int carry = solve(head->next);

        // add carry to current node
        head->val = carry;

        // extract carry and update digit
        carry = head->val / 10;
        head->val %= 10;

        return carry;
    }

    Node* addOne(Node* head) {
        int carry = solve(head);

        // if carry still exists, create new node at front
        if(carry) {
            Node* newHead = new Node(carry);
            newHead->next = head;
            return newHead;
        }

        return head;
    }
};

int main() {
    return 0;
}