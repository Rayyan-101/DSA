#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    vector<vector<int>> adj;
    int N;
    const int INF = 1e9;

    Graph(int n, vector<vector<int>>& edges) {
        N = n;
        adj = vector<vector<int>>(n, vector<int>(n, INF));
        
        // initialize from given edges
        for (auto &vec : edges) {
            int u    = vec[0];
            int v    = vec[1];
            int cost = vec[2];
            adj[u][v] = min(adj[u][v], cost);  // in case of multiple edges
        }
        
        // distance to self = 0
        for (int i = 0; i < n; i++) {
            adj[i][i] = 0;
        }
        
        // Floyd–Warshall to precompute all-pairs shortest paths
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < N; i++) {
                if (adj[i][k] == INF) continue;
                for (int j = 0; j < N; j++) {
                    if (adj[k][j] == INF) continue;
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        int u    = edge[0];
        int v    = edge[1];
        int cost = edge[2];

        // If this edge itself is better, update direct distance
        if (cost < adj[u][v]) {
            adj[u][v] = cost;

            // Relax all-pairs using this new edge (like incremental Floyd–Warshall)
            for (int i = 0; i < N; i++) {
                if (adj[i][u] == INF) continue;
                for (int j = 0; j < N; j++) {
                    if (adj[v][j] == INF) continue;
                    adj[i][j] = min(adj[i][j], adj[i][u] + cost + adj[v][j]);
                }
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        return adj[node1][node2] >= INF ? -1 : adj[node1][node2];
    }
};

int main() {
    // Example:
    int n = 4;
    vector<vector<int>> edges = {
        {0, 1, 5},
        {0, 2, 10},
        {1, 3, 3}
    };

    Graph g(n, edges);

    cout << g.shortestPath(0, 3) << "\n"; // 5 + 3 = 8
    cout << g.shortestPath(0, 2) << "\n"; // 10

    g.addEdge({2, 3, 1}); // new better path 0 -> 2 -> 3 = 11

    cout << g.shortestPath(0, 3) << "\n"; // min(8, 11) = 8
    cout << g.shortestPath(2, 3) << "\n"; // 1

    return 0;
}
