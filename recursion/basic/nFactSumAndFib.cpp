#include<iostream>
using namespace std;

// Function to find the sum of first N numbers
int nSum(int n) {
    if(n == 1) return 1;

    return n + nSum(n - 1);
}

// Function to find the factorial of a number
int nFactorial(int n) {
    if(n == 1) return 1;

    return n * nFactorial(n - 1);
}

// Function to find the fibonacci of a number
int fibonacci(int n) {
    if(n == 0 || n == 1) return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    cout << nSum(5);

    cout << nFactorial(5);

    cout << fibonacci(8);
    
    return 0;   
}