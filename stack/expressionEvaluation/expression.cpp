#include <bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return -1;
}

string infixToPostfix(string s) {
    stack<char> st;
    string result;

    for(char c : s) {

        // Operand → add to result
        if(isalnum(c)) {
            result += c;
        }

        // Opening bracket
        else if(c == '(') {
            st.push(c);
        }

        // Closing bracket
        else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }

        // Operator
        else {
            while(!st.empty() && precedence(st.top()) >= precedence(c)) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop remaining operators
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {
    string s = "";
}