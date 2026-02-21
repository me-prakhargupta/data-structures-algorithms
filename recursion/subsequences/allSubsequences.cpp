#include<iostream>
#include<vector>
using namespace std;

// Idea: At every index → either take or skip → 2^n tree
// A subsequence is derived from an array/string by: Maintaining original order

void findAllSubsequences(vector<int>& nums, int st, vector<int> ans) {
    // Base case: if all elements are processed
    if(st >= nums.size()) {
        // Print the current subsequence
        for(int num : ans) cout << num << " ";
        cout << endl;
        return;
    }

    // Choice 1: Include current element (only if it maintains non-decreasing order)
    // Condition ensures subsequence remains increasing
    if(ans.empty() || nums[st] >= ans.back()) {
        ans.push_back(nums[st]); // take
        findAllSubsequences(nums, st + 1, ans);  // recurse
        ans.pop_back(); // backtrack (restore state)
    }

    // Choice 2: Exclude current element
    // Move to next index without changing current subsequence
    findAllSubsequences(nums, st + 1, ans);
}

void findAllSubsequencesWithSumK(vector<int>& nums, int st, int sum, int k, vector<int>& ans) {
    // Base case: all elements have been processed
    if(st >= nums.size()) {
        // If current subsequence sum equals target k, print it
        if(sum == k) {
            for(int num : ans) cout << num << " ";
            cout << endl;
        }

        return;
    }

    // Choice 1: Include current element in subsequence
    // Add nums[st] to current path and update sum
    ans.push_back(nums[st]);
    findAllSubsequencesWithSumK(nums, st + 1, sum + nums[st], k, ans);

    // Backtrack: remove the last added element before exploring next choice
    ans.pop_back();

    // Choice 2: Exclude current element from subsequence
    // Move to next index without changing sum or path
    findAllSubsequencesWithSumK(nums, st + 1, sum, k, ans);
}

int countSubsequencesWithSumK(vector<int>& nums, int st, int sum, int k) {
    // Base case: if all elements are processed
    if(st >= nums.size()) {
        // If current subsequence sum equals k, count this as 1 valid way
        // Otherwise, it's not a valid subsequence → return 0
        return (sum == k) ? 1 : 0;
    }

    // Choice 1: Include current element in subsequence
    // Add nums[st] to sum and move to next index
    int left = countSubsequencesWithSumK(nums, st + 1, sum + nums[st], k);

    // Choice 2: Exclude current element from subsequence
    // Keep sum unchanged and move to next index
    int right = countSubsequencesWithSumK(nums, st + 1, sum, k);

    // Total valid subsequences = sum of both choices
    return left + right;
}

bool checkSubsequencesWithSumK(vector<int>& nums, int st, int sum, int k) {
    // Base case: if we have considered all elements
    if(st >= nums.size()) {
        // Check if the current subsequence sum equals target k
        return (sum == k);
    }

    // Choice 1: Include current element in subsequence
    // Add nums[st] to sum and move to next index
    bool left = checkSubsequencesWithSumK(nums, st + 1, sum + nums[st], k);

    // Choice 2: Exclude current element from subsequence
    // Keep sum unchanged and move to next index
    bool right = checkSubsequencesWithSumK(nums, st + 1, sum, k);

    // If either including or excluding leads to a valid subsequence, return true
    return left || right;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    // findAllSubsequences(nums, 0, {});
    // vector<int> ans;
    // findAllSubsequencesWithSumK(nums, 0, 0, 5, ans);
    // cout << countSubsequencesWithSumK(nums, 0, 0, 5);
    // cout << checkSubsequencesWithSumK(nums, 0, 0, 16);
    return 0;
}