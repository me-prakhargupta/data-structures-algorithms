#include<iostream>
#include<string>
using namespace std;

// Approach 1 -> Using stack (Brute force)

// Approach 2 -> Using counter (optimal)
string removeOutermostParentheses(string s) {
    int count = 0;
    string answer = "";

    for(char c : s) {
        if(c == ')') count--;
        if(count != 0) answer += c;
        if(c == '(') count++;
    }

    return answer;
}

// Time complexity -> O(n)
// Space complexity -> O(1);

/**
 * We have to remove the outermost parentheses
 * Maintain a counter -> whenever a counter becomes = 0, stop storing the answer
 * and start again the fresh
*/

int main() {
    string s = "(()())(())";
    cout << removeOutermostParentheses(s);
    return 0;
}