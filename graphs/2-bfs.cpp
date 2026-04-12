/*
BFS: Breadth First Search
- Travel immediate neighbour first and mark visited
- Level by Level traversal
- Uses Queue

Time Complexity
- Worst Case: O(V + E)
*/

#include<iostream>
#include<queue>
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

    void bfs() {
        vector<bool> visited(V, false);
        queue<int> q;

        q.push(0);
        visited[0] = true;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            cout << node << " ";
            for(int neighbours : adj[node]) {
                if(!visited[neighbours]) {
                    visited[neighbours] = true;
                    q.push(neighbours);
                }
            }
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.bfs();
    return 0;
}