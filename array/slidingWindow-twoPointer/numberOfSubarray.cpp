#include<iostream>
#include<vector>
using namespace std;

int atMost(vector<int>& nums, int goal) {
    int left = 0, sum = 0, count = 0;

    for(int right = 0; right < nums.size(); right++) {
        sum += (nums[right] % 2);

        while(sum > goal) {
            sum -= (nums[left] % 2);
            left++;
        }

        // Count all subarrays ending at right
        count += (right - left + 1);
    }

    return count;
}

int numberOfSubarrays(vector<int>& nums, int k) {
    return atMost(nums, k) - atMost(nums, k - 1);
}


int main() {
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    cout << numberOfSubarrays(nums, k);
    return 0;
}