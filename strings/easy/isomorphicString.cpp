#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

// Using array
bool isIsomorphicArray(string s, string t) {
    if (s.size() != t.size()) return false;

    vector<char> mapS(256, -1), mapT(256, -1);

    for(int i = 0; i < s.size(); i++) {
        if(mapS[s[i]] != mapT[t[i]]) {
            return false;
        }

        mapS[s[i]] = i;
        mapT[t[i]] = i;
    }

    return true;
}

// Using hashmap
bool isIsomorphicHash(string s, string t) {
    if (s.size() != t.size()) return false;

    unordered_map<char, char> sToT;
    unordered_map<char, char> tToS;

    for (int i = 0; i < s.size(); i++) {
        if (sToT.count(s[i]) && sToT[s[i]] != t[i]) return false;
        if (tToS.count(t[i]) && tToS[t[i]] != s[i]) return false;

        sToT[s[i]] = t[i];
        tToS[t[i]] = s[i];
    }
    return true;
}

int main() {
    string s = "egg", t = "ade";

    cout << isIsomorphicArray(s, t);

    return 0;
}