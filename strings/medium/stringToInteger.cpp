#include<iostream>
#include<string>
using namespace std;

int myAtoi(string s) {
    int i = 0, n = s.size(), sign = 1;

    // remove leading spaces
    while(i < n && s[i] == ' ') i++;

    // if no char available => return 0;
    if(i == n) return 0;

    // lookout for sign
    if(i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }


    long res = 0;

    // lookup for digit
    while(i < n && isdigit(s[i])) {
        res = res * 10 + (s[i] - '0');
        
        if(sign == 1 && res > INT_MAX) {
            return INT_MAX;
        }

        if(sign == -1 && -res < INT_MIN) {
            return INT_MIN;
        }

        i++;
    }

    return sign * res;
}

int main() {
    string s = "42";
    cout << myAtoi(s);
    return 0;
}