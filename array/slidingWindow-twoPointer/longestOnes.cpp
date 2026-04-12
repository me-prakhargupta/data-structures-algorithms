#include<iostream>
#include<vector>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int left = 0, zeroCount = 0, maxLen = 0;
    
    // Expand the window using right pointer
    for(int right = 0; right < nums.size(); right++) {

        // Count zeros in the current window
        if(nums[right] == 0) {
            zeroCount++;
        }

        // If zeros exceed k, shrink window from left
        while(zeroCount > k) {
            if(nums[left] == 0) {
                zeroCount--; // remove a zero from window
            }
            left++; // shrink window
        }

        // Update max length of valid window
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    
    cout << longestOnes(nums, k);
    return 0;
}