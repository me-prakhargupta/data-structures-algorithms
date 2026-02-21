#include<iostream>
#include<stack>
#include<string>
using namespace std;

string reverseString(string s) {
    stack<char> st;

    for(char c : s) st.push(c);

    string word = "";

    while(!st.empty()) {
        word += st.top();
        st.pop();
    }

    return word;
}

// Time: O(n), Space: O(n) (extra stack used)
// Optimal: swap(s[i], s[j]) - i: 0, j: s.length() - 1

int main() {
    string s = "car";
    cout << reverseString(s);
    return 0;
}