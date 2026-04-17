#include<iostream>
#include<vector>
#include<string>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    vector<int> freq(26, 0);

    int left = 0, maxFreq = 0, maxLen = 0;

    for(int right = 0; right < s.length(); right++) {
        // Add current character
        freq[s[right] - 'A']++;

        // Track maximum frequency in current window
        // whenever the freq get updated, extract the max freq with each character
        maxFreq = max(maxFreq, freq[s[right] - 'A']);

        // If more than k replacements needed, shrink window
        // (right - left + 1) => current length of substring
        while((right - left + 1) - maxFreq > k) {
            freq[s[left] - 'A']--;
            left++;
        }

        // Update answer
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    string s = "ABAB";
    int k = 2;
    
    cout << characterReplacement(s, k);

    return 0;
}