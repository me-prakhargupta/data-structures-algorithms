#include<iostream>
#include<vector>
using namespace std;

bool canFinishHelper(int start, int parent, vector<bool>& visited, vector<vector<int>>& prerequisities) {
    visited[start] = true;

    for(int neigh : prerequisities[start]) {
        if(canFinishHelper(neigh, start, visited, prerequisities)) {
            return true;
        } else if(neigh != parent) {
            return true;
        }
    }

    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisities) {
    vector<bool> visited(numCourses, false);

    for(int i = 0; i < numCourses; i++) {
        if(canFinishHelper(i, -1, visited, prerequisities)) {
            return true;
        }
    }

    return false;
}

int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisities = {
        {1, 0},
        {0, 1}
    };

    cout << canFinish(numCourses, prerequisities);
    return 0;
}