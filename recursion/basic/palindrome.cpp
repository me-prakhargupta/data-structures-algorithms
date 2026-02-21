#include<iostream>
#include<string>
using namespace std;

bool palindrome(string s, int left, int right) {
    // Base case: pointers crossed or met
    if(left >= right) return true;

    // If mismatch → not palindrome
    if(s[left] != s[right]) return false;
        
    // Move inward
    return palindrome(s, left + 1, right - 1);
}

bool isPalindrome(string s) {
    return palindrome(s, 0, s.length() - 1);
}

int main() {
    cout << isPalindrome("madam");
    
    return 0;
}