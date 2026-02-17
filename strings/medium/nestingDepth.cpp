#include<iostream>
#include<vector>
using namespace std;

int maxDepth(string s) {
    int count = 0, maxDepth = 0;

    for(char c : s) {
        if(c == '(') {
            count++;
            maxDepth = max(maxDepth, count);
        }

        if(c == ')') count--;
        else continue;
    }

    return maxDepth;
}

int main() {
    string s = "()(())((()()))";
    cout << maxDepth(s);
    return 0;
}