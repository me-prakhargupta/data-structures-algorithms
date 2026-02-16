#include<iostream>
#include<string>
using namespace std;

bool rotateString(string& s, string& goal) {
    if(s.size() != goal.size()) {
        return false;
    }

    // (s + s) -> ab cdeab cde => look for cdeab in that
    // if found it return true else false 
    
    // string::npos is a sentinel value returned by find() 
    // to indicate the substring was not found
    return (s + s).find(goal) != string::npos;
}

int main() {
    string s = "abcde", goal = "cdeab";
    cout << rotateString(s, goal);
    return 0;
}