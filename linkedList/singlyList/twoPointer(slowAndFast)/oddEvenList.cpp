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

    // Function to group all the nodes with odd indices together,
    // followed by the nodes with even indices
    Node* oddEvenList(Node* head) {
        if(!head || !head->next) return head;

        Node* odd = head; // 0 index node
        Node* even = head->next; // 1 index node
        Node* evenHead = even; // // save start of odd list

        while(even && even->next) {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead; // attach even list at end

        return head;
    }
};

int main() {
    return 0;
}