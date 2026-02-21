#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// The solution set contain duplicate combinations.
// Combination Sum I helper
void solveCombinationSum(vector<int>& nums, int target, int idx, vector<int>& ans, vector<vector<int>>& res) {
    // Base case: target achieved
    if(target == 0) {
        res.push_back(ans);
        return;
    }

    // Base case: out of bounds OR target exceeded
    if(idx >= nums.size() || target < 0) return;

    // Choice 1: Take current element
    ans.push_back(nums[idx]);
    solveCombinationSum(nums, target - nums[idx], idx, ans, res);  // stay at same index
    ans.pop_back();  // backtrack

    // Choice 2: Skip current element
    solveCombinationSum(nums, target, idx + 1, ans, res);
}

// The solution set contain duplicate combinations.
// Combination Sum I
vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> res;
    vector<int> ans;

    solveCombinationSum(nums, target, 0, ans, res);

    return res;
}

// The solution set must not contain duplicate combinations.
// Combination Sum II helper
void solveCombinationSumWithoutDup(vector<int>& nums, int target, int idx, vector<int>& ans, vector<vector<int>>& res) {
     // Base case: target achieved
    if(target == 0) {
        res.push_back(ans);
        return;
    }

    
    for(int i = idx; i < nums.size(); i++) {
        // Skip duplicates at same recursion level
        if(i > idx && nums[i] == nums[i - 1]) continue;

        // Optimization: stop if element exceeds target
        if(nums[i] > target) break;

        ans.push_back(nums[i]); // take
        solveCombinationSumWithoutDup(nums, target - nums[i], i + 1, ans, res);  // move forward
        ans.pop_back(); // backtrack
    }
}

// The solution set must not contain duplicate combinations.
// Combination Sum II
vector<vector<int>> combinationSumWithoutDup(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> res;
    vector<int> ans;

    solveCombinationSumWithoutDup(nums, target, 0, ans, res);

    return res;
}

int main() {
    // vector<int> nums = {2,3,6,7};
    vector<int> nums = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> res = combinationSumWithoutDup(nums, target);
    for(vector<int> nums : res) {
        for(int num : nums) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}