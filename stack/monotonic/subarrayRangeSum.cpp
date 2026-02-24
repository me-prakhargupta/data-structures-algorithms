#include <iostream>
#include <vector>
#include <stack>
using namespace std;

long long subArrayRanges(vector<int>& nums) {
    int n = nums.size();
    
    vector<int> ple(n), nle(n), pse(n), nse(n);
    stack<int> st;

    // Previous Less Element (for minimum)
    for(int i = 0; i < n; i++) {
        while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    // Next Less Element
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    // Previous Greater Element (for maximum)
    for(int i = 0; i < n; i++) {
        while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
        ple[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    // Next Greater Element
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
        nle[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    long long minSum = 0, maxSum = 0;

    for(int i = 0; i < n; i++) {
        long long left = i - pse[i];
        long long right = nse[i] - i;
        minSum += (long long)nums[i] * left * right;
    }

    for(int i = 0; i < n; i++) {
        long long left = i - ple[i];
        long long right = nle[i] - i;
        maxSum += (long long)nums[i] * left * right;
    }

    return maxSum - minSum;
}