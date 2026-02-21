#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>& st, int k) {
    if(k == 1) {
        st.pop();
        return;
    }

    int temp = st.top();
    st.pop();

    solve(st, k - 1);

    st.push(temp);
}

void deleteMid(stack<int>& st) {
    int n = st.size();
    
    int k = (n / 2) + 1;
    solve(st, k);
}

int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    
    deleteMid(st);
    
    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}