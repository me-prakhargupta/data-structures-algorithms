#include<iostream>
#include<vector>
using namespace std;

int countDegrees(int start, vector<vector<int>>& matrix) {
    int m = matrix[start].size(), edges = 0;
    
    for(int i = 0; i < m; i++) {
        if(matrix[start][i] == 1) {
            edges++;
        }
    }

    return edges;
}

vector<int> findDegrees(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<int> degrees;

    for(int i = 0; i < n; i++) {
        int degree = countDegrees(i, matrix);
        degrees.push_back(degree);
    }

    return degrees;
}

int main() {
    vector<vector<int>> matrix = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };

    vector<int> degrees = findDegrees(matrix);
    for(int degree : degrees) cout << degree << " ";
    return 0;
}