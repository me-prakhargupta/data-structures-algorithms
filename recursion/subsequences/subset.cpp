#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// Idea: At every index → either take or skip → 2^n tree
// A subsequence is derived from an array/string by: Order does NOT matter

// Function to find subsets with unique elements
void powerSet(vector<int>& nums, vector<int>& ans, int idx) {
    // Base case: if all elements are processed
    if(idx >= nums.size()) {
        // Print the current subset
        for(int num : ans) cout << num << " ";
        cout << endl;
        return;
    }

    // Choice 1: Include current element
    ans.push_back(nums[idx]); // take
    powerSet(nums, ans, idx+1); // recurse to next index

    // Backtrack: remove the last added element
    ans.pop_back();

    // Choice 2: Exclude current element 
    // Move to next index without including current element
    powerSet(nums, ans, idx+1);
}

void solve(vector<int>& nums, int idx, vector<int>& ans, vector<vector<int>>& res) {
    // Store current subset
    res.push_back(ans);

    for(int i = idx; i < nums.size(); i++) {

        // Skip duplicates at same recursion level
        if(i > idx && nums[i] == nums[i + 1]) continue;
        ans.push_back(nums[i]);     // take
        solve(nums, i, ans, res);   // move forward
        ans.pop_back();             // backtrack
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> res;
    vector<int> ans;

    solve(nums, 0, ans, res);

    return res;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<int> ans;
    powerSet(nums, ans, 0);
    return 0;
}