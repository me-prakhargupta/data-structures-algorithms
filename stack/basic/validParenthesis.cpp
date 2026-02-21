#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for(char c : s) {
        // Push closing brackets for current opening brackets
        if(c == '(') st.push(')');
        else if(c == '[') st.push(']');
        else if(c == '{') st.push('}');
        else {
            // Check if stack is empty + Check matching
            if(st.empty() || st.top() != c) return false;
            st.pop();
        }
    }

    return st.empty();
}

int main() {
    string s = "()";
    cout << isValid(s);
    return 0;
}