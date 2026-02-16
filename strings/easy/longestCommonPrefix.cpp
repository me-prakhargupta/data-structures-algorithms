#include<iostream>
#include<string>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()) return "";

    // Conside only first word of vector
    for(int i = 0; i < strs[0].size(); i++) {
        // Extract the first character
        char c = strs[0][i];

        // Iterate over vector from word + 1
        for(int j = 1; j < strs.size(); j++) {
            // at any moment index of strs[0] exceed the size of current word
            // or at any moment the current word character does not match to
            // first word character -> 
            // return the common word till i (common index)
            if(i >= strs[j].size() || strs[j][i] != c) {
                return strs[0].substr(0, i);
            }
        }
    }

    // if nothing return from above, it means -> first word from vector in common
    return strs[0];
}

int main() {
    vector<string> strs = {"flower","flow","flight"};
    cout << longestCommonPrefix(strs);
    return 0;
}