#include<iostream>
#include<string>
using namespace std;

int minAddToMakeValid(string s) {
    int open = 0, close = 0;

    // parenthese validity depends upon prefix validity, not just on totals
    for(char c : s) {
        if(c == '(') {
            open++;
        } else {
            if(open > 0) {
                open--; // match with '('
            } else {
                close++; // extra ')'
            }
        }
    }

    return open + close;
}

int main() {
    string s = "())";
    cout << minAddToMakeValid(s);
    return 0;
}