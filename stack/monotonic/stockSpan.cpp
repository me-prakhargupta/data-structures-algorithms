#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// Function to calculate stock span for each day
vector<int> calculateSpan(vector<int>& arr) {

    int n = arr.size();
    vector<int> span(n);
    stack<int> st; // Monotonic decreasing stack (stores indices)

    // Traverse from left to right
    for(int i = 0; i < n; i++) {
        
        // Remove all previous days with price <= current price
        // because they are included in the current span
        while(!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }

        // If stack is not empty, top gives nearest greater element on left
        if(!st.empty()) {
            span[i] = i - st.top(); // Distance from last greater element
        } else {
            span[i] = i + 1; // when no greater element on left
        }

        // Push current index for future comparisons
        st.push(i);
    }

    return span;
}

int main() {
    vector<int> stock = {100, 80, 90, 120};

    vector<int> ans = calculateSpan(stock);
    for(int num : ans) cout << num << " ";
    
    return 0;
}