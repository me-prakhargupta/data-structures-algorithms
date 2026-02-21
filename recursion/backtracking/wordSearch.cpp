#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool solve(int row, int col, int index, string word, vector<vector<char>>& board) {
    // Base case: all characters matched
    if(index == word.length()) return true;

    int rows = board.size();
    int cols =board[0].size();

    // Boundary + mismatch check
    // - out of grid
    // - character doesn't match current index
    if(row < 0 || col < 0 || row >= rows || col >= cols ||
         board[row][col] != word[index]) 
        return false;

    // Directions: Down, Left, Right, Up
    int di[] = {1, 0, 0, -1};
    int dj[] = {0, -1, 1, 0};

    // Mark current cell as visited (in-place)
    char temp = board[row][col];
    board[row][col] = '$';

    // Explore all 4 directions
    for(int k = 0; k < 4; k++) {
        if(solve(row + di[k], col + dj[k], index + 1, word, board))
            return true; // early return if path found
    }

    // Backtrack: restore original value
    board[row][col] = temp;

    return false;
}

bool exist(vector<vector<char>>& board, string word) {

    // Try starting from every cell
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {

            // start from (i (intially: 0), j (intially: 0))
            if(solve(i, j, 0, word, board)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    string word = "ABCCED";

    cout << exist(board, word);

    return 0;
}