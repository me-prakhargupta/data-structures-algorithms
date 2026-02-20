#include<iostream>
using namespace std;

class Node{
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

    // Brute Force: Use hashmap to store node of list1
    // iterate through list2 and if node got match
    // return that node
    // Constraint: Don't work for duplicate nodes

    // Better: Find the length of both the node
    // Diff: Subtract smaller length from larger one 
    // Move larger list to diff node
    // Iterate each node and return the first common node

    Node* listIntersection(Node* head1, Node* head2) {
        Node* temp1 = head1;
        Node* temp2 = head2;

        while(temp1 != temp2) {
            temp1 = temp1? temp1->next : head2;
            temp2 = temp2? temp2->next : head1;
        }

        return temp1; // can be intersection node or nullptr
    }
};

int main() {
    return 0;
}