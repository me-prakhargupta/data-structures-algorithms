#include<iostream>
using namespace std;

// Function to print numbers from 1 to N
void print1ToN(int n) {
    // Base case
    if(n == 0) return;

    // Recursive call
    // First, call recursion for smaller numbers
    print1ToN(n - 1);

    // Then print after the recursive call
    cout << n << " ";
}

// Funtion to print numbers from N to 1
void printNto1(int n) {
    if(n == 0) return;

    cout << n << " ";

    printNto1(n - 1);
}

int main() {
    print1ToN(10);

    printNto1(10);

    return 0;
}