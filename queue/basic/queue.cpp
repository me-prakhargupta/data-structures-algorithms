#include<iostream>
#include<queue>
using namespace std;

// Manual Implementation (Array)
// class Queue {
//     int q[1000];
//     int f;
//     int r;

// public:

//     Queue() {
//         f = 0;
//         r = -1;
//     }

//     void push(int val) {
//         if(r == 999) {
//             cout << "Queue overflow\n";
//             return;
//         }

//         q[++r] = val;
//     }

//     void pop() {
//         if(empty()) {
//             cout << "Queue underflow\n";
//             return;
//         }

//         f++;
//     }

//     int front() {
//         if(empty()) {
//             cout << "Queue underflow\n";
//             return -1;
//         }

//         return q[f];
//     }

//     bool empty() {
//         return f > r;
//     }
// };

// Manual Implementation (Linked List)
// class Node {
// public:
//     int val;
//     Node* next;

//     Node(int val) {
//         this->val = val;
//         this->next = nullptr;
//     }
// };

// class Queue {
//     Node* head;
//     Node* tail;

// public:
//     Queue() {
//         head = tail = nullptr;
//     }

//     void push(int val) {
//         Node* newNode = new Node(val);

//         if(!head) {
//             head = tail = newNode;
//             return;
//         } else {
//             tail->next = newNode;
//             tail = newNode;
//         }
//     }

//     void pop() {
//         if(!head) {
//             cout << "Queue is Empty\n";
//             return;
//         }

//         Node* temp = head;
//         head = head->next;
//         if(head == nullptr) {
//             tail = nullptr;
//             return;
//         }

//         delete temp;
//     }

//     int front() {
//         if(!head) {
//             cout << "Queue is empty\n";
//             return -1;
//         }

//         return head->val;
//     }

//     bool empty() {
//         return head == nullptr;
//     }

//     void display() {
//         if(!head) {
//             cout << "Queue is empty\n";
//             return;
//         }

//         Node* temp = head;
//         while(temp != nullptr) {
//             cout << temp->val << " ";
//             temp = temp->next;
//         }
//     }
// };

int main() {
   queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    // q.display();
    // q.empty();
    cout << q.front();
    return 0;
}