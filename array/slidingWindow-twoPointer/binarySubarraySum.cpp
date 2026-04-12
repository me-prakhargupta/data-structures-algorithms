#include<iostream>
#include<vector>
using namespace std;

// Given a binary array nums and an integer goal, 
// return the number of non-empty subarrays with a sum goal.

int atMost(vector<int>& nums, int goal) {
    int left = 0, sum = 0, count = 0;

    for(int right = 0; right < nums.size(); right++) {
        sum += nums[right];

        while(sum > goal) {
            sum -= nums[left];
            left++;
        }

        // Count all subarrays ending at right
        count += (right - left + 1);
    }

    return count;
}

int numberOfBinarySubarraySum(vector<int>& nums, int goal) {
    return atMost(nums, goal) - atMost(nums, goal - 1);
}

int main() {
    vector<int> nums = {1,0,1,0,1};
    int goal = 2;

    cout << numberOfBinarySubarraySum(nums, goal);
    return 0;
}