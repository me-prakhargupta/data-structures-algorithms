#include<iostream>
#include<string>
#include<vector>
using namespace std;

/**
 * Core Idea (Backtracking)
 * We place queens row by row.
 * At each row:
 * Try placing queen in every column
 * Check if it's safe
 * If safe → place → recurse
 * Else → skip
 * After recursion → backtrack (remove queen)

 * Safety Check Logic
 * A position (row, col) is safe if:
 * No queen in same column
 * No queen in left diagonal ↖
 * No queen in right diagonal ↗
*/

// Check if it's safe to place queen at (row, col)
bool isSafe(int row, int col, vector<string>& board, int n) {

    
   
    // Check column
    for(int i = 0; i < row; i++) {
        if(board[i][col] == 'Q') return false;
    }
 
    // Check left diagonal
    // use && because: The loop should run only while BOTH i and j are valid
    // to ensure both stay within bounds, otherwise there is a risk accessing invalid memory.
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 'Q') return false;
    }

    // Check right diagonal
    for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if(board[i][j] == 'Q') return false;
    }

    return true;
}

void solve(int row, int n, vector<string>& board, vector<vector<string>>& res) {
    // Base case: all queens placed
    if(row == n) {
        res.push_back(board);
        return;
    }

    // Try placing queen in each column
    for(int col = 0; col < n; col++) {
        if(isSafe(row, col, board, n)) {

            // Choose
            board[row][col] = 'Q';

            // Explore next row
            solve(row + 1, n, board, res);

            // Backtrack
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));

    solve(0, n, board, res);

    return res;
}

int main() {
    int n = 4;
    vector<vector<string>> ans = solveNQueens(n);
    for(vector<string> res : ans) {
        for(string s : res) cout << s << " ";
        cout << endl;
    }
    return 0;
}