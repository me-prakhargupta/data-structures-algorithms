#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

/**
 * Brute Force
 * Generate all the substring
 * While generating all the substring, use a hashmap vector to keep the track of repeating charater
 * If a repeated character got found, break the loop
 * And if this not happen, keep storing the length of current substring
 * Time Complexity: O(n^2)
 * 
 * Note: On any problem such as finding the substring max or min
 * Think for two pointer / sliding window
 */

int lengthOfLongestSubstring(string s) {
    vector<int> lastSeen(255, -1); // stores last index of character
    int left = 0, maxLen = 0;

    for(int right = 0; right < s.length(); right++) {
        char ch = s[right];

        // If character already seen and inside current window
        if(lastSeen[ch] >= left) {
            left = lastSeen[ch] + 1;
        }

        lastSeen[ch] = right; // update last seen index
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s);
    return 0;
}