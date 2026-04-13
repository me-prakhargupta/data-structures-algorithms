#include<iostream>
#include<vector>
using namespace std;

void getComponent(int start, vector<bool>& visited, vector<vector<int>>& adj, vector<int>& component) {
    visited[start] = true;
    component.push_back(start);

    for(int neigh : adj[start]) {
        if(!visited[neigh]){
            getComponent(neigh, visited, adj, component);
        }
    }
}

vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    for(vector<int> edge : edges) {
        int u = edge[0], v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> components;
    vector<bool> visited(V, false);

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            vector<int> component;
            getComponent(i, visited, adj, component);
            components.push_back(component);
        }
    }
    return components;
}

int main() {
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1},
        {2, 1},
        {3, 4}
    };

    vector<vector<int>> components = getComponents(V, edges);
    for(vector<int> component : components) {
        for(int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}