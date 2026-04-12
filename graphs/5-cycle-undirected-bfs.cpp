#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V): V(V), adj(V) {};

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool detectCycleUsingBFS(int start, vector<bool>& visited) {
        queue<pair<int, int>> q; // store parent of each node for comparison
        q.push({start, -1});

        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(int neighbour : adj[node]) {
                if(!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push({neighbour, node});
                } else if(neighbour != parent) {
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle() {
        vector<bool> visited(V, false);
        return detectCycleUsingBFS(0, visited);
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    if(g.isCycle()) {
        cout << "Cycle detected \n";
    } else {
        cout << "No cycle detected \n";
    }
    return 0;
}