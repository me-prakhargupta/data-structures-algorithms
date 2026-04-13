#include<iostream>
#include<vector>
using namespace std;

void dfsIsland(int i, int j, vector<vector<char>>& grid, int n, int m) {
    if(i < 0 || j < 0 || i > n || j > m || grid[i][j] != '1') {
        return;
    }

    // visited[i][j] = true; 
    grid[i][j] = '0'; // to optimize space complexity

    dfsIsland(i, j + 1, grid, n, m); // top
    dfsIsland(i + 1, j, grid, n, m); // right
    dfsIsland(i, j - 1, grid, n, m); // bottom
    dfsIsland(i - 1, j, grid, n, m); // left
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    // vector<vector<bool>> visited(n, vector<bool>(m, false));

    int islands = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] != '0') {
                dfsIsland(i, j, grid, n, m);
                islands++;
            }
        }
    }

    return islands;
}

int main() {
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    cout << "Total no. of Islands are: " << numIslands(grid) << endl;
    return 0;
}