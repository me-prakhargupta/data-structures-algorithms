/*
# What is Topological Sort?
- Topological ordering is a way to arrange the vertices of a directed graph such that:
- For every directed edge u -> v, node u appears before v in ordering
- Applicable only on DAG (Directed acyclic graph)
*/

#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;

    for(int neigh : adj[node]) {
        if(!visited[neigh]) {
            dfs(neigh, adj, visited, st);
        }
    }

    st.push(node);
}

// DFS Technique
vector<int> topoSort(int V, vector<vector<int>> edges) {
    vector<vector<int>> adj(V);
    for(const auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
    }

    stack<int> st;
    vector<bool> visited(V, false);

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }

    vector<int> ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

void bfs() {

} 

// BFS Technique: Kahn's Algorithm
vector<int> topologicalSort(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    for(const auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
    }

    vector<int> indegree(V, 0);
    for(int u = 0; u < V; u++) {
        for(int v : adj[u]) {
            indegree[v]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < indegree.size(); i++) {
        if(indegree[i] == 0) q.push(i);
    }
    
    vector<int> ans;
    while(!q.empty()) {
        int node = q.front();
        q.pop();

        ans.push_back(node);
        
        for(int neigh : adj[node]) {
            indegree[neigh]--;
            if(indegree[neigh] == 0) q.push(neigh);
        }
    }

    return ans;
}

int main() {
    int V = 4;
    vector<vector<int>> edges = {
        {3, 0},
        {1, 0},
        {2, 0}
    };
    
    vector<int> result = topologicalSort(V, edges);
    for(int res : result) cout << res << " ";

    return 0;
}