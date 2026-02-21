#include<iostream>
#include<vector>
using namespace std;

vector<int> reverse(vector<int>& nums, int left, int right) {
    if(left >= right) return nums;

    swap(nums[left], nums[right]);

    return reverse(nums, left + 1, right - 1);
}

vector<int> reverseArray(vector<int>& nums) {
    reverse(nums, 0, nums.size() - 1);
    
    return nums;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};

    vector<int> output = reverseArray(nums);
    for(int num : nums) cout << num << " ";

    return 0;
}