#include<iostream>
#include<string>
using namespace std;

// This code will give TLE for a very large string
// int repeatedStringMatch(string a, string b) {
//     if(a.find(b) != string::npos) {
//         return 0;
//     }

//     string temp = a;
//     int count = 1, i = 0;
//     while(i < (int)b.length()) {
//         temp += a;
//         count++;
//         if(temp.find(b) != string::npos) {
//             return count;
//             break;
//         }
//         i++;
//     }

//     return 0;
// }


int repeatedStringMatch(string a, string b) {
    string temp = a;
    int count = 1;

    // Repeat until temp is at least as long as b
    while(temp.length() < b.length()) {
        temp += a;
        count++;
    }

    if(temp.find(b) != string::npos) {
        return count;
    }

    // One extra repetition to cover overlap
    temp += a;
    count++;

    if(temp.find(b) != string::npos) {
        return count;
    }

    return -1;
}

int main() {
    string a = "abcd", b ="cdabcdab";
    cout << repeatedStringMatch(a, b);
    return 0;
}