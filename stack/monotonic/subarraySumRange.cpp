#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
    Core Idea:
    Answer = Sum of all subarray maximums - Sum of all subarray minimums

    Instead of iterating over all subarrays,
    we calculate contribution of each element.

    Contribution Formula:
    nums[i] * (#subarrays where it is min or max)

    #subarrays = left * right
*/

long long subarrayMin(vector<int>& nums) {
    int n = nums.size();

    // left[i]  -> number of elements to the left where nums[i] is the minimum
    // right[i] -> number of elements to the right where nums[i] is the minimum
    vector<int> left(n), right(n);

    stack<int> st;

    /*
        STEP 1: Previous Smaller Element (STRICT)
        Find how far we can extend to the left
        Condition: strictly smaller (>) to avoid duplicate counting
    */
    for(int i = 0; i < n; i++) {
        while(!st.empty() && nums[st.top()] > nums[i]) {
            st.pop();
        }

        // If stack empty → all elements on left are greater
        // Otherwise → distance from previous smaller
        left[i] = st.empty() ? i + 1 : i - st.top();

        st.push(i);
    }

    // Clear stack for reuse
    while(!st.empty()) st.pop();

    /*
        STEP 2: Next Smaller Element (NON-STRICT)
        Find how far we can extend to the right
        Condition: >= to handle duplicates properly
    */
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && nums[st.top()] >= nums[i]) {
            st.pop();
        }

        // If stack empty → all elements on right are greater
        // Otherwise → distance to next smaller
        right[i] = st.empty() ? n - i : st.top() - i;

        st.push(i);
    }

    /*
        STEP 3: Contribution Calculation
        Each element contributes:
        nums[i] * left[i] * right[i]
    */
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += (long long) nums[i] * left[i] * right[i];
    }

    return sum;
}

long long subarrayMax(vector<int>& nums) {
    int n = nums.size();

    // Same concept, but now for maximum contribution
    vector<int> left(n), right(n);

    stack<int> st;

    /*
        STEP 1: Previous Greater Element (STRICT)
        Condition: strictly smaller (<)
    */
    for(int i = 0; i < n; i++) {
        while(!st.empty() && nums[st.top()] < nums[i]) {
            st.pop();
        }

        left[i] = st.empty() ? i + 1 : i - st.top();

        st.push(i);
    }

    while(!st.empty()) st.pop();

    /*
        STEP 2: Next Greater Element (NON-STRICT)
        Condition: <= for handling duplicates
    */
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && nums[st.top()] <= nums[i]) {
            st.pop();
        }

        right[i] = st.empty() ? n - i : st.top() - i;

        st.push(i);
    }

    /*
        STEP 3: Contribution Calculation
    */
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += (long long) nums[i] * left[i] * right[i];
    }

    return sum;
}

/*
    Final Function:
    Range = max - min
*/
long long subarrayRanges(vector<int>& nums) {
    return subarrayMax(nums) - subarrayMin(nums);
}

int main() {
    vector<int> nums = {1, 2, 3};

    cout << subarrayRanges(nums);

    return 0;
}