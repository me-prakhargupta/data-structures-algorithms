#include<iostream>
#include<string>
using namespace std;

void longestPrefix(string& s) {
    int n = s.length();
    string ans = "";

    for(int len = 0; len < n; len++) {
        if(s.substr(0, len) == s.substr(n - len, len)) {
            ans = s.substr(0, len);
        }
    }

    cout << ans;
}

int main() {
    string s = "ababab";
    longestPrefix(s);
    return 0;
}