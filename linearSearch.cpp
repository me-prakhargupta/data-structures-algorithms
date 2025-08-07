#include<iostream>
#include<vector>
using namespace std;

int linearSearch(vector<int>& nums, int target) {
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {3,2,4,5,6,2,1,7,8};
    int target = 5;
    cout << "Element found at index: " << linearSearch(nums, target) << endl;
    return 0;
}