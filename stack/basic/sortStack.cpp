#include<iostream>
#include<stack>
using namespace std;

/**
 * Core Idea (Very Important)
 * You can’t access middle elements directly, so:
 * Pop the top element
 * Recursively sort remaining stack
 * Insert popped element in correct position
 */

void insertSorted(stack<int>& st, int x) {
    if(st.empty() || st.top() <= x) {
        st.push(x);
        return;
    }

    int temp = st.top();
    st.pop();

    insertSorted(st, x);

    st.push(temp);
}

void sortStack(stack<int>& st) {
    int temp = st.top();
    st.pop();

    sortStack(st);

    insertSorted(st, temp);
}

int main() {
    return 0;
}