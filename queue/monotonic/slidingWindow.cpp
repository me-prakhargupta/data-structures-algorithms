#include<iostream>
#include<deque>
#include<vector>
using namespace std;

// Returns the maximum of each sliding window of size k
// Uses a monotonic decreasing deque to achieve O(n) time complexity
vector<int> slidingWindowMax(vector<int>& nums, int k) {
    vector<int> res;
    deque<int> dq; // Monotonic decreasing deque storing indices

    for(int i = 0; i < nums.size(); i++) {

        // 1. Remove indices that are out of the current window [i-k+1, i]
        if(!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // 2. Maintain decreasing order in deque
        // Remove all elements smaller than current element (they'll never be useful)
        while(!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        // 3. Add current index to deque
        dq.push_back(i);

        // 4. Start adding results once the first window is fully formed
        // The front of deque always holds index of maximum element
        if(i >= k - 1) {
            res.push_back(nums[dq.front()]);
        }
    }

    return res;
}

// Returns the minimum of each sliding window of size k
// Uses a monotonic increasing deque to achieve O(n) time complexity
vector<int> slidingWindowMin(vector<int>& nums, int k) {
    vector<int> res;
    deque<int> dq; // Monotonic increasing deque storing indices

    for(int i = 0; i < nums.size(); i++) {

        // 1. Remove indices that are out of the current window [i-k+1, i]
        if(!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // 2. Maintain increasing order in deque
        // Remove all elements greater than current element (they won't be useful)
        while(!dq.empty() && nums[dq.back()] > nums[i]) {
            dq.pop_back();
        }

        // 3. Add current index to deque
        dq.push_back(i);

        // 4. Start recording results once the first window is formed
        // The front of deque always holds index of minimum element
        if(i >= k - 1) {
            res.push_back(nums[dq.front()]);
        }
    }

    return res;
}

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = slidingWindowMin(nums, k);
    for(int num : ans) cout << num << " ";
    return 0;
}