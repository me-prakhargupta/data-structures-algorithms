#include<iostream>
#include<string>
#include<vector>
using namespace std;

int beautySum(string& s) {
    int n = s.size(), beauty = 0;

    for(int i = 0; i < n; i++) {
        // use a vector map to store the freq of char in all substrings
        vector<int> freq(26, 0);

        for(int j = i; j < n; j++) {
            // store the freq of char
            freq[s[j] - 'a']++;

            int maxFreq = 0;
            int minFreq = INT_MAX;

            for(int k = 0; k < n; k++) {
                // lookup for freq(s)
                if(freq[k] > 0) {
                    maxFreq = max(maxFreq, freq[k]);
                    minFreq = min(minFreq, freq[k]);
                }
            }

            // real beauty is high freq - low freq
            beauty += (maxFreq - minFreq);
        }
    }

    return beauty;
}

int main() {
    string s = "aabcbaa";
    cout << beautySum(s);
    return 0;
}