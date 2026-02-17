#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Brute Force Approach => Time Complexity: O(n^3)
bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    while(left <= right) {
        if(s[left] != s[right]) return false;
        left++;
        right--;
    }

    return true;
}

void substring(string& s) {
    vector<string> ans;
    for(int i = 0; i < s.size(); i++) {
        for(int j = i; j < s.size(); j++) {
            string st = "";
            for(int k = i; k <= j; k++) {
                st += s[k];
            }
            ans.push_back(st);
        }
    }

    int maxLen = 0;
    string result = "";
    for(string st : ans) {
        if(isPalindrome(st)) {
            if(st.size() > maxLen) {
                maxLen = st.size();
                result = st;
            }
        }
    }

    cout << result;
}

// string longestPalindromSubstring(string& s) {
//     int left = 0, right = s.size() - 1;
//     int st = -1, end = -1;
//     while(left <= right) {
//         if(s[left] = s[right]) {
            
//         } else {
//             left++;
//             right--;
//         }
//     }
// }

int main() {
    string s = "babad";
    // cout << longestPalindromSubstring(s);
    substring(s);
    return 0;
}