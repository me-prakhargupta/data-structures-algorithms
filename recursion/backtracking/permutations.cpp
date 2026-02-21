#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// Permutation = Arrangements
// Total no. of permutations for n: n! (n factorial)

// Helper function to find all the permutation with unique elements
void solvePermutationsWithoutDuplicateElements(vector<int>& nums, int index, vector<vector<int>>& res) {
    // Base case: if index reaches end, we formed one permutation
    if(index >= nums.size()) {
        res.push_back(nums); // store current permutation
        return;
    }

    // Try placing every element at current index
    for(int i = index; i < nums.size(); i++) {

        // Step 1: Choose → place nums[i] at current index
        swap(nums[index], nums[i]);

        // Step 2: Explore → fix next index
        solvePermutationsWithoutDuplicateElements(nums, index + 1, res);

        // Step 3: Backtrack → restore original state
        swap(nums[index], nums[i]);
    }
}

// Main function to find all the permutations with unique elements
vector<vector<int>> permutations(vector<int>& nums) {
    vector<vector<int>> res;

    // Start recursion from index 0
    solvePermutationsWithoutDuplicateElements(nums, 0, res);

    return res;
}

// Helper function to generate permutations with duplicates
void solvePermutationsWithDuplicateElements(vector<int>& nums, int index, vector<vector<int>>& res) {
    // Base case: if index reaches end, store current permutation
    if(index >= nums.size()) {
        res.push_back(nums);
        return;
    }

    // Try placing each element at current index
    for(int i = index; i < nums.size(); i++) {

        // Skip duplicates:
        // If current element is same as previous and previous wasn't used at this position
        if(i > index && nums[i] == nums[i - 1]) continue;

        // Step 1: Choose → place nums[i] at current index
        swap(nums[index], nums[i]);

        // Step 2: Explore → recursively fix next index
        solvePermutationsWithDuplicateElements(nums, index + 1, res);

        // Step 3: Backtrack → restore original order
        swap(nums[index], nums[i]);
    }
}

// Main function to generate permutations with duplicates elements
vector<vector<int>> permutationWithDup(vector<int>& nums) {
    // Sort to bring duplicates together (important for skipping logic)
    sort(nums.begin(), nums.end());

    vector<vector<int>> res;

     // Start recursion from index 0
    solvePermutationsWithDuplicateElements(nums, 0, res);

    return res;
}

int main() {
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> res = permutationWithDup(nums);
    for(vector<int> nums : res) {
        for(int num : nums) cout << num << " ";
        cout << endl;
    }
    
    return 0;
}
