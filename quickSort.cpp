#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& nums, int start, int end) {
    int pivot = nums[end];
    int idx = start-1;

    for(int i = start; i < end; i++) {
        if(nums[i] <= pivot) {
            idx++;
            swap(nums[i], nums[idx]);
        }
    }
    
    idx++;
    swap(nums[idx], nums[end]);
    return idx;
}

void quickSort(vector<int>& nums, int start, int end) {
    if(start < end) {
        int pivIdx = partition(nums, start, end);
        quickSort(nums, start, pivIdx-1);
        quickSort(nums, pivIdx+1, end);
    }
}

int main() {
    vector<int> nums = {4,3,5,6,2,1,7};
    quickSort(nums, 0, nums.size()-1);

    cout << "Quick Sort: ";
    for(int val : nums) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}