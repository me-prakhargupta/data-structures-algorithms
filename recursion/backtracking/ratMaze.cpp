#include<iostream>
#include<string>
#include<vector>
using namespace std;

/**
 * Core Idea
 * 
 * At each cell:
 * Try moving in 4 directions:
 * Down (D)
 * Left (L)
 * Right (R)
 * Up (U)
 * Only move if:
 * Inside bounds: cell is 1
 * Not already visited
 * 
 * Approach (Step-by-Step)
 * 
 * Start from (0,0)
 * Maintain: path (string like "DRRD")
 * visited[][]
 * Explore all 4 directions
 * Backtrack (unmark visited)
 */

void solve(int row, int col, vector<vector<int>>& maze, int n, vector<string>& res, string path, vector<vector<int>>& visited) {
    // Base case: reached destination
    if(row == n - 1 && col == n - 1) {
        res.push_back(path);
        return;
    }

    visited[row][col] = 1;

    // Down
    if(row + 1 < n && maze[row + 1][col] == 1 && !visited[row + 1][col]) {
        solve(row + 1, col, maze, n, res, path + 'D', visited);
    }

    // Left
    if(col - 1 >= 0 && maze[row][col - 1] == 1 && !visited[row][col - 1]) {
        solve(row, col - 1, maze, n, res, path + 'L', visited);
    }

    // Right
    if(col + 1 < n && maze[row][col + 1] == 1 && !visited[row][col + 1]) {
        solve(row, col + 1, maze, n, res, path + 'R', visited);
    }

    // Up
    if(row - 1 >= 0 && maze[row - 1][col] == 1 && !visited[row - 1][col]) {
        solve(row - 1, col, maze, n, res, path + 'U', visited);
    }

    // Backtrack: unmark visited
    visited[row][col] = 0;
}

vector<string> findPath(vector<vector<int>>& maze) {
    vector<string> res;

    // Edge case: start blocked
    if(maze[0][0] == 0) return res;

    int n = maze.size();
    vector<vector<int>> visited(n, vector<int>(n, 0));

    solve(0, 0, maze, n, res, "", visited);

    return res;
}

int main() {
    vector<vector<int>> maze = {{
        1, 0, 0, 0}, 
        {1, 1, 0, 1}, 
        {1, 1, 0, 0}, 
        {0, 1, 1, 1}
    };

    vector<string> res = findPath(maze);
    for(string s : res) cout << s << endl;

    return 0;
}