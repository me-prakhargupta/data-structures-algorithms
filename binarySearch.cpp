#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& nums, int target) {
    int start = 0, end = nums.size();
    while(start < end) {
        int mid = start + (end-start)/2;
        if(nums[mid] == target) {
            return mid;
        } else if(nums[mid] < target) {
            start = mid+1;
        } else {
            end = mid-1;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {1,3,5,7,9,11,15};
    int target = 11;
    cout << binarySearch(nums, target);
    return 0;
}