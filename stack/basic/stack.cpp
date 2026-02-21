#include<iostream>
#include<stack>
using namespace std;

// Manual Implementation (Array)
// class Stack {
//     int arr[100];
//     int top;

// public:
//     Stack() {
//         top = -1;
//     }

//     // push O(1)
//     void push(int x) {
//         if(top == 99) {
//             cout << "Overflow" << endl;
//         }

//         arr[++top] = x;
//     }

//     // pop O(1)
//     void pop() {
//         if(top == -1) {
//             cout << "Underflow" << endl;
//             return;
//         }

//         top--;
//     }

//     // peek O(1)
//     int peek() {
//         if(top == -1) return -1;
//         return arr[top];
//     }
// };

// Manual Implementation (Linked List)
// class Node {
// public:
//     int val;
//     Node* next;

//     Node(int x) {
//         val = x;
//         next = nullptr;
//     }
// };

// class Stack {
// public:
//     Node* top;

//     Stack() {
//         top = nullptr;
//     }

//     void push(int x) {
//         Node* newNode = new Node(x);
//         newNode->next = top;
//         top = newNode;
//     }

//     void pop() {
//         if(!top) {
//             cout << "Stack underflow" << endl;
//             return;
//         }

//         Node* temp = top;
//         top = top->next;
//         delete temp;
//     }

//     int peek() {
//         if(!top) {
//             cout << "Stack is empty" << endl;
//             return -1;
//         }

//         return top->val;
//     }

//     bool empty() {
//         return !top;
//     }
// };

int main() {
    // Implementation Using STL
    stack<int> st;
    st.push(1);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    return 0;
}