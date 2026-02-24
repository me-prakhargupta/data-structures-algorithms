#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// Function to find Next Greater Element (NGE) for each element
vector<int> nextGreaterElement(vector<int>& nums) {

    int n = nums.size();
    vector<int> ans(n); // Stores the result (NGE for each index)
    stack<int> st; // Monotonic decreasing stack

    // Traverse from right to left
    for(int i = n - 1; i >= 0; i--) {

        // Remove all elements smaller than or equal to current element
        // because they can never be the next greater element
        while(!st.empty() && st.top() <= nums[i]) st.pop();

        // If stack is empty -> no greater element exists
        if(st.empty()) {
            ans[i] = -1;
        } 
        // Top of stack is the next greater element
        else {
            ans[i] = st.top();
        }

        // Push current element to stack for future comparisons
        st.push(nums[i]);
    }

    return ans;
}

// Next Greater Element II (Circular Array)
vector<int> nextGreaterElements(vector<int>& nums) {

    int n = nums.size();
    vector<int> ans(n, -1); // Initialize result with -1 (default if no larger element exists)
    stack<int> st; // Monotonic decreasing stack

    // Traverse twice (simulate circular array)
    for(int i = 2*n - 1; i >= 0; i--) {

        int curr = nums[i % n];

        // Remove all smaller/equal elements
        while(!st.empty() && st.top() <= curr) {
            st.pop();
        }

        // Fill answer only in first pass
        if(i < n) {
            if(!st.empty()) {
                ans[i] = st.top();
            }
        }

        // Push current element
        st.push(curr);
    }

    return ans;
}

// Function to find Next Smaller Element (NSE) for each element
vector<int> nextSmallerElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1); // Initialize result with -1 (default if no smaller element exists)
    stack<int> st; // Monotonic increasing stack

    // Traverse from right to left
    for(int i = n-1; i >= 0; i--) {

        // Remove all elements greater than or equal to current element
        // because they cannot be the next smaller element
        while(!st.empty() && st.top() >= nums[i]) {
            st.pop();
        }

        // If stack is not empty, top element is the next smaller element
        if(!st.empty()) {
            ans[i] = st.top();
        }

        // Push current element for future comparisons
        st.push(nums[i]);
    }
    return ans;
}

int main() {
    vector<int> nums = {4, 8, 5, 2, 25};

    vector<int> ans = nextSmallerElement(nums);
    for(int num : ans) cout << num << " ";

    return 0;
}