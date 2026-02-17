// #include<iostream>
// #include<algorithm>
// #include<string>
// #include<unordered_map>
// #include<utility>
// #include<vector>
// using namespace std;

#include <bits/stdc++.h>
using namespace std;

string sortByFrequencies(string& s) {
    // store the freq of each character in hashmap
    unordered_map<char, int> freq;
    for(char c : s) freq[c]++;

    // here store the hashmap in vector using pair<char, int>
    vector<pair<char, int>> chars(freq.begin(), freq.end());

    // sort the chars array -> max freq of character using lambda function
    sort(chars.begin(), chars.end(), 
        [](auto& a, auto& b) {
            // return the element that have greater freq
            return a.second > b.second;
    });

    string result;
    // append the char in result
    for(auto& p : chars) {
        // appending chars in result based on => max freq of chars
        // p.second => no. of times to append
        // p.first => which char have to append
        result.append(p.second, p.first);
    }

    return result;
}

int main() {
    string s = "tree";
    cout << sortByFrequencies(s);
    return 0;
}