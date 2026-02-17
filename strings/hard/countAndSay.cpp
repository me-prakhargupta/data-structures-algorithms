#include<iostream>
#include<string>
using namespace std;

/** Count and say example 
 * (upar wali line mein kya kitni baar likha hua hai)
 * i: 1 => 1
 * i: 2 => 11
 * i: 3 => 21
 * i: 4 => 1211
 * i: 5 => 111221
 */

string countAndSay(int n) {
    // Base case
    if(n == 1) {
        return "1";
    }

    string say = countAndSay(n - 1);
    string result = "";

    // Processing
    for(int i = 0; i < say.length(); i++) {
        char ch = say[i];
        int count = 1;

        // Move while the chars are same
        while(i < say.length() - 1 && say[i] == say[i + 1]) {
            count++;
            i++;
        }

        // string(1, ch) => convert 1 char into string
        result += to_string(count) + string(1, ch);
    }


    return result;
}

int main() {
    int n = 4;
    cout << countAndSay(n);
    return 0;
}