#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Z-Algorithm => all the occurances of pattern
// This code will give TLE for larger text
// vector<int> searchPattern(string& txt, string& pat) {
//     // Pattern is larger than Text
//     if(pat.length() > txt.length()) {
//         return {};
//     }

//     vector<int> ans;
//     int n = txt.length(), m = pat.length();

//     int t = 0; // text index
//     int p = 0; // pattern index

//     while(t < n) {
//         if(txt[t] == pat[p]) {
//             t++;
//             p++;

//             if(p == m) {
//                 ans.push_back(t - m);
//                 // reset the overlapping matches
//                 p = 0;
//                 t = t - m + 1;
//             }
//         } else {
//             // mismatch fix
//             t = t - p + 1;
//             p = 0;
//         }
//     }

//     return ans;
// }

vector<int> searchPattern(string txt, string pat) {
    
}

int main() {
    string txt = "geeksforgeeks", pat = "geek";

    vector<int> output = searchPattern(txt, pat);
    for(int x : output) cout << x << " ";

    return 0;
}