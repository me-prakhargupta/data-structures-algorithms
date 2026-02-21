#include<iostream>
using namespace std;

int countDigits (int num) {
    // Handle negative numbers
    if(num < 0) num = -num;

    // Base case: single digit (including 0)
    if(num < 10) return 1;

    return 1 + countDigits(num / 10);
}

int digitSum(int num) {
    if(num < 0) num = -num;
    if(num < 10) return num;

    return num % 10 + digitSum(num / 10);
}

int main() {
    cout << countDigits(333300);

    cout << digitSum(-123);
    
    return 0;
}