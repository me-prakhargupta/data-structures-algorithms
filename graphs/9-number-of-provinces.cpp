#include<iostream>
#include<vector>
using namespace std;

// DFS Approach
void checkProvinces(int start, vector<bool>& visited, vector<vector<int>>& isConnected) {
    visited[start] = true;

    for(int i = 0; i < isConnected[start].size(); i++) {
        if(isConnected[start][i] == 1 && !visited[i]) {
            checkProvinces(i, visited, isConnected);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int provinces = 0, n = isConnected.size();
    vector<bool> visited(n, false);

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            checkProvinces(i, visited, isConnected);
            provinces++;
        }
    }

    return provinces;
}

int main() {
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    cout << "Total no. of provinces are: " << findCircleNum(isConnected) << endl;
    return 0;
}