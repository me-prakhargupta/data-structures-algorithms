#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// Brute force O(n^3)
int subarraySumMinimum(vector<int>& nums) {
    int n = nums.size();
    int subarraySum = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int minNum = INT_MAX;
            for(int k = i; k <= j; k++) {
                minNum = min(minNum, nums[k]);
            }

            subarraySum += minNum;
        }
    }

    return subarraySum;
}

int sumSubarrayMin(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(n), right(n);
    stack<int> st;

    // Previous Smaller Element (strictly smaller)
    for(int i = 0; i < n; i++) {
        while(!st.empty() && nums[st.top()] > nums[i]) {
            st.pop();
        }
        left[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }

    // Clear stack
    while(!st.empty()) st.pop();

    // Next Larger Element
    for(int i = n-1; i >= 0; i--) {
        while(!st.empty() && nums[st.top()] < nums[i]) {
            st.pop();
        }
        right[i] = st.empty() ? n - i : st.top() - i;
        st.push(i);
    }

    // Final sum
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += nums[i] * left[i] * right[i];
    }

    return sum;
}

int main() {
    vector<int> nums = {3, 1, 2, 4};
    cout << sumSubarrayMin(nums);
    return 0;
}