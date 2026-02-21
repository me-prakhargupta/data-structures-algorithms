#include<iostream>
using namespace std;

// Function to calculate x^n, both for positive and negative power
// Brute Force
double powerXN(double x, double n) {
    if(n == 0) return 1;
    if(x == 0) return 0;

    if(n < 0) {
        x = 1 / x;
        n = -n;
    }

    return x * powerXN(x, n - 1);
}

// Helper function: computes x^n using binary exponentiation (O(log n))
double power(double x, long long n) {
    // Base case: anything raised to power 0 is 1
    if(n == 0) return 1;

    // Recursively compute half power
    double half = power(x, n / 2);

    // If n is even: x^n = (x^(n/2))^2
    // If n is odd:  x^n = x * (x^(n/2))^2
    return (n % 2 == 0) ? half * half : x * half * half;
}

// Main function: handles negative powers and edge cases
double myPow(double x, int n) {
    // Edge case: 0^n = 0 (for n > 0)
    if(x == 0) return 0;

    // Base case: x^0 = 1
    if(n == 0) return 1;

    // Use long long to safely handle INT_MIN
    long long N = n;

     // Handle negative exponent: x^-n = (1/x)^n
    if(N < 0) {
        x = 1 / x;
        N = -N;
    }

    // Compute power using optimized recursion
    return power(x, N);
}

int main() {
    cout << powerXN(2, -2);
    
    return 0;
}