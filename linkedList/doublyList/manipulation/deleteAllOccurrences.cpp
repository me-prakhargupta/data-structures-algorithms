#include<iostream>
using namespace std;

class Node {
public: 
    int val;
    Node* next;
    Node* prev;

    Node(int val) {
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void deleteAllOccurrences(int val) {
        if(!head) {
            cout << "Empty list" << endl;
            return;
        }

        Node* temp = head;
        while(temp) {
            if(temp->val == val) {
                Node* nodeToDelete = temp;

                // Move temp first (important!)
                temp = temp->next; 

                // If node is head
                if(nodeToDelete->prev == nullptr) {
                    head = nodeToDelete->next;
                    
                    if(head) head->prev = nullptr;
                } else {
                    nodeToDelete->prev->next = nodeToDelete->next;
                    if(nodeToDelete->next)
                        nodeToDelete->next->prev = nodeToDelete->prev;
                }
                
                delete nodeToDelete;
            } else {
                temp = temp->next;
            }

        }
    }
};

int main() {
    return 0;
}