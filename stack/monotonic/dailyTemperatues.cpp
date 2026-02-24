#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// Function to find number of days until a warmer temperature
vector<int> dailyTemperatures(vector<int>& temperatures) {
    
    int n = temperatures.size();
    vector<int> waits(n, 0);     // Stores result (default 0 if no warmer day exists)
    stack<int> st;               // Monotonic decreasing stack (stores indices)

    // Traverse from right to left
    for(int i = n-1; i >= 0; i--) {

        // Remove all days with temperature less than or equal to current
        // because they cannot be the next warmer day
        while(!st.empty() && temperatures[st.top()] <= temperatures[i]) {
            st.pop();
        }

        // If stack is not empty, top index gives the next warmer day
        if(!st.empty()) {
            waits[i] = st.top() - i;   // Distance between days
        }

        // Push current index for future comparisons
        st.push(i);
    }

    return waits;
}

int main() {
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    return 0;
}