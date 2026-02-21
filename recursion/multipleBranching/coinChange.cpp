#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// Helper function to find the fewest number of coins that need to make up that amount.
void solveCoinChange(vector<int>& coins, int amount, int idx, vector<int>& ans, int& minCoins) {
    // Base case: exact amount formed
    if(amount == 0) {
        minCoins = min(minCoins, (int)ans.size());
        return;
    }

    // Out of bounds
    if(idx >= coins.size()) return;

    // Choice 1: Take coin (reuse allowed)
    if(coins[idx] <= amount) {
        ans.push_back(coins[idx]); // take
        solveCoinChange(coins, amount - coins[idx], idx, ans, minCoins); // move forward
        ans.pop_back(); // backtrack
    }

    // Choice 2: Skip coin
    solveCoinChange(coins, amount, idx + 1, ans, minCoins);
}
// Main function to find the fewest number of coins that need to make up that amount.
int coinChange(vector<int>& coins, int amount) {
    int minCoins = INT_MAX;
    vector<int> ans;
    
    solveCoinChange(coins, amount, 0, ans, minCoins);

    return (minCoins == INT_MAX) ? -1 : minCoins;
}

// Helper function to find the number of combinations that make up that amount.
void solveChange(vector<int>& coins, int amount, int idx, vector<int>& ans, int& ways) {
    // Base case: valid combination found
    if(amount == 0) {
        ways++; // increment total ways
        return;
    }

    // Base case: no coins left to explore
    if(idx >= coins.size()) return;

    // Choice 1: Take current coin (reuse allowed)
    if(coins[idx] <= amount) {
        ans.push_back(coins[idx]); // include coin
        solveChange(coins, amount - coins[idx], idx, ans, ways); // stay at same index
        ans.pop_back(); // backtrack
    }

    // Choice 2: Skip current coin 
    // Move to next index to avoid duplicate combinations
    solveChange(coins, amount, idx + 1, ans, ways);
}

// Main function to find the number of combinations that make up that amount.
int change(vector<int>& coins, int amount) {
    int ways = 0;
    vector<int> ans;

    // Start recursion from index 0
    solveChange(coins, amount, 0, ans, ways);

    return ways;
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    cout << change(coins, amount);
    return 0;
}