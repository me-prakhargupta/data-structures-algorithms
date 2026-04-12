/*
DFS: Depth First Search
- Goes depth first
- Uses Recursion* / Stack

Time Complexity
- Worst Case: O(V + E)
*/

#include<iostream>
#include<vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V), adj(V) {};

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfsHelper(int start, vector<bool>& visited) {
        cout << start << " ";
        visited[start] = true;

        for(int neighbour : adj[start]) {
            if(!visited[neighbour]) {
                dfsHelper(neighbour, visited);
            }
        }
    }

    void dfs() {
        vector<bool> visited(V, false);
        int start = 0;

        dfsHelper(start, visited);
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.dfs();
    return 0;
}