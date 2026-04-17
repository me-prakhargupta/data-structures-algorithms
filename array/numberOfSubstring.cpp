#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

// Brute Force: Generate All the substring 
int numberOfSubstrings(string s) {
    int n = s.length();
    int count = 0;

    for(int left = 0; left < n; left++) {
        for(int right = left; right < n; right++) {
            string temp = s.substr(left, right - left + 1);

            if(temp.find('a') != string::npos &&
                temp.find('b') != string::npos &&
                temp.find('a') != string::npos) {
                count++;
            }
        }
    }

    return count;
}

// Optimal Approach: Sliding Window
int numberOfSubstring(string s) {
    int n = s.length();
    
    int lastA = -1, lastB = -1, lastC = -1;
    int count = 0;

    for(int i = 0; i < n; i++) {
        // Update last seen positions
        if(s[i] == 'a') lastA = i;
        if(s[i] == 'b') lastB = i;
        if(s[i] == 'c') lastC = i;

        // If all characters are seen
        if(lastA != -1 && lastB != -1 && lastC != -1) {
            count += min({lastA, lastB, lastC}) + 1;
        }
    }

    return count;
}

int main() {
    string s = "abcabc";
    
    cout << numberOfSubstrings(s);
    return 0;
}