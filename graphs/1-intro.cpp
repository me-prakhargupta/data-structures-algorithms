/* 
# What is a Graph? 
- A graph is way to represent relationships or 
- A network (set) of nodes(vertices) + edges(connections)
- Graph = nodes + relationships + traversal


# Core Terminology
- Vertex(Node): Represents an entity
- Edge: Represents a relationship between two nodes
- Degree: Number of edges connected (in-degree and out-degree)
- Path: Sequence of nodes connected by edges
- Cycle: Path that start and end at same node
- Connected Graph: Every node is reachable from every other node
- Components: Diconnected pieces of Graph


# Types of Graphs
1. Undirected(bi-directed) Graph: Connection is two-way
    e.g. A -- B is same as B -- A

2. Directed(uni-directed) Graph: Connection is one-way
    e.g. A -- B != B -- A

3. Weighted: Edges have cost (distance, time)

4. Unweighted: no cost, just connection


# Graph Representation
1. Adjacency Matrix: 2D Array
        A B C
    A [ 0 1 1 ]
    B [ 1 0 0 ]
    C [ 1 0 0 ]

    Pros: Easy to check edge -> O(1)
    Cons: Space heavy -> O(n^2)

2. Adjacency List: Each node store its neighbors
    A → B, C
    B → A
    C → A

    Pros: Space Efficient O(V + E), Used in real systems (industry standard)
*/

#include<iostream>
#include<vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    // Graph(int V) {
    //     this->V = V;
    //     this->adj = vector<vector<int>>(V);
    // }
    
    Graph(int V) : V(V), adj(V) {};

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void print() {
        for(int i = 0; i < V; i++) {
            cout << i << ": ";
            for(int neighbour : adj[i]) {
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.print();
    return 0;
}