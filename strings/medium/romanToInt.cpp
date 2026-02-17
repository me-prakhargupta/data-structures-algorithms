#include<bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
    // store all roman number in to map
    unordered_map<char, int> value = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500},
        {'M', 1000}
    };

    int result = 0;
    for(int i = 0; i < s.size(); i++) {
        // if current char have element and if that is greater than
        // current element then it will be subtracted
        if(i + 1 < s.size() && value[s[i]] < value[s[i + 1]]) {
            result -= value[s[i]];
        // else it will be added to final result
        } else {
            result += value[s[i]];
        }
    }

    return result;
}

int main() {
    string s = "LVIII";
    cout << romanToInt(s);
}