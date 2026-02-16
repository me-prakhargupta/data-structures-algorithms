#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

//Using array
bool isAnagramArray(string& s, string t) {
    if(s.size() != t.size()) {
        return false;
    }

    vector<int> freq(26, 0);
    for(char c : s) freq[c -'a']++;
    for(char c : t) freq[c - 'a']--;

    for(int x : freq) {
        if(x != 0) return false;
    }

    return true;
}

//Using hashmap
bool isAnagramHash(string& s, string t) {
    if(s.size() != t.size()) {
        return false;
    }

    unordered_map<char, int> map;
    for(char c : s) map[c]++;
    for(char c : t) map[c]--;

    for(auto& p : map) {
        if(p.second != 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    string s = "nagaram", t = "anagram";
    cout << isAnagramArray(s, t);
    return 0;
}