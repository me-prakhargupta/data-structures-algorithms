#include<iostream>
#include<unordered_map>
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

    void removeDuplicate() {
        if(!head) {
            cout << "Empty List";
            return;
        }

        unordered_map<int, int> freq;

        Node* temp = head;
        while(temp) {
            freq[temp->val]++;
            temp = temp->next;
        }

        temp = head;
        while(temp) {
            if(freq[temp->val] > 1) {
                Node* nodeToDelete = temp;

                temp = temp->next;

                freq[nodeToDelete->val]--;

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