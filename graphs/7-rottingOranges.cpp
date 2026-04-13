#include<iostream>
#include<vector>
using namespace stdl

int orangesRottings(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 2) {

            }
        }
    }
}

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {0, 1, 1},
        {0, 1, 1}
    };

    return 0;
}