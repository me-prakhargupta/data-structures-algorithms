#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

// Brute Force Approach
int countSubstringB(string& s) {
    int n = s.size();
    int count = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            // generate a substring (sub)
            string sub = s.substr(i, j - i + 1);

            // does this substring (sub) contains (find) a, b, c
            // if => count += 1, else continue
            if(sub.find('a') != string::npos && 
                sub.find('b') != string::npos && 
                sub.find('c') != string::npos) {
                count++;
            }
        }
    }
    return count;
}

int countSubstrings(string& s) {
    vector<int> last(3, -1);
    int count = 0;

    for(int i = 0; i < s.size(); i++) {
        last[s[i] - 'a'] = i;

        count += 1 + min({last[0], last[1], last[2]});
    }

    return count;
}

int main() {
    string s = "aaacb";
    cout << countSubstringB(s);
    return 0;
}