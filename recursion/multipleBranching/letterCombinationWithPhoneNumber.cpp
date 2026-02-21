#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

// Recursive function to build all possible letter combinations
void solve(string digits, int idx, string& ans, vector<string>& res, unordered_map<char, string>& mp) {
    
    // Base case: all digits are processed
    if(idx >= digits.length()) {
        // Store the current combination
        res.push_back(ans);
        return;
    }

    // Get current digit and its corresponding letters
    char ch = digits[idx];
    string st = mp[ch];

    // Try all possible letters for current digit
    for(char c : st) {

        // Choice: pick current character
        ans.push_back(c);

        // Recurse to process next digit
        solve(digits, idx + 1, ans, res, mp);

        // Backtrack: remove last character to explore other options
        ans.pop_back();
    }
}

// Main function to initialize mapping and start recursion
vector<string> letterCombination(string digits) {

    // Edge case: empty input
    if(digits.empty()) return {};

    // Mapping of digits to corresponding letters (phone keypad)
    unordered_map<char, string> mp = {
        {'2', "abc"}, {'3', "def"},
        {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };

    vector<string> res;
    string ans = "";

    // Start recursion from index 0
    solve(digits, 0, ans, res, mp);

    return res;
}

int main() {
    string digits ="23";

    // Generate all possible combinations
    vector<string> ans = letterCombination(digits);

    // Print results
    for(string s : ans) cout << s << endl;

    return 0;
}