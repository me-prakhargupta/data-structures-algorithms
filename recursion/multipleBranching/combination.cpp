#include<iostream>
#include<vector>
using namespace std;

void solve(int n, int k, int idx, vector<int>& ans, vector<vector<int>>& res) {

    // Base case: required k elements have been selected
    if(k == 0) {
        // Store the current combination
        res.push_back(ans);
        return;
    }

    // Try all possible choices from current index to n
    for(int i = idx; i <= n; i++) {
        // Choice: include current number
        ans.push_back(i);

        // Recurse: 
        // - k - 1 → one element is picked 
        // - i + 1 → move forward (no reuse allowed)
        solve(n, k - 1, i + 1, ans, res);

        // Backtrack: remove last element to explore next choices
        ans.pop_back();
    }
}

vector<vector<int>> combination(int n, int k) {
    vector<vector<int>> res;
    vector<int> ans;

    // Start building combinations from 1
    solve(n, k, 1, ans, res);

    return res;
}

int main() {
    int n = 4, k = 2;
    vector<vector<int>> ans = combination(n, k);
    for(vector<int> nums : ans) {
        for(int num : nums) cout << num << " ";
        cout << endl;
    }
    return 0;
}