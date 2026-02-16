#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string reverseWords(string s) {
    // First reverse the entire sentence
    reverse(s.begin(), s.end());

    int len = s.length();
    string answer = "";
    for(int i = 0; i< len; i++) {
        string word = "";
        while(i < len && s[i] != ' ') {
            word += s[i++];
        }

        // Reverse each word from sentence to make meaningful word
        reverse(word.begin(), word.end());

        // Only append in answer string if word is valid
        if(!word.empty()) {
            answer += " " + word;
        }
    }

    return answer.substr(1);
}

// Time Complexity: O(n);
// Space Complexity: O(n);

int main() {
    string s = "       hello world          ";
    cout << reverseWords(s);
    return 0;
}