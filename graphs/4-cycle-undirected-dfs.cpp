#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public: 
    Graph(int V) : V(V), adj(V) {};

    bool detectCycleUsingDFS(int start, int par, vector<bool>& visited) {
        visited[start] = true;

        for(int neighbour : adj[start]) {
            if(!visited[neighbour]) {
                if(detectCycleUsingDFS(neighbour, start, visited)) {
                    return true;
                }
            } else if(neighbour != par) {
                return true;
            }
        }

        return false;
    }

    bool isCycle() {
        vector<bool> visited (V, false);

        // For disconnected graph
        // for(int i = 0; i < V; i++) {
        //     if(!visited[i]) {
        //         if(detectCycleUsingDFS(i, -1, visited)) {
        //             return true;
        //         }
        //     }
        // }

        return detectCycleUsingDFS(0, -1, visited);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 4);

    if(g.isCycle()) {
        cout << "Cycle detected \n";
    } else {
        cout << "No cycle detected \n";
    }
    return 0;
}