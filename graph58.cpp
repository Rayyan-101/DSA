class Solution {
private:
    const int INF = INT_MIN;

    // Performs DFS-based Topological Sort
    void topoSort(int node,
                  vector<int>& visited,
                  stack<int>& topoStack,
                  vector<pair<int, int>> adj[]) {

        visited[node] = 1;

        // Visit all unvisited neighbours
        for (auto& edge : adj[node]) {
            int neighbour = edge.first;

            if (!visited[neighbour]) {
                topoSort(neighbour, visited, topoStack, adj);
            }
        }

        // Add node after all its neighbours are processed
        topoStack.push(node);
    }

public:
    vector<int> maxDistance(int vertices,
                             int source,
                             vector<vector<int>>& edges) {

        // -------------------------------------------------
        // Step 1: Build the adjacency list
        // -------------------------------------------------
        vector<pair<int, int>> adj[vertices];

        for (auto& edge : edges) {
            int from = edge[0];
            int to   = edge[1];
            int wt   = edge[2];

            adj[from].push_back({to, wt});
        }

        // -------------------------------------------------
        // Step 2: Find Topological Ordering
        // -------------------------------------------------
        vector<int> visited(vertices, 0);
        stack<int> topoStack;

        for (int node = 0; node < vertices; node++) {
            if (!visited[node]) {
                topoSort(node, visited, topoStack, adj);
            }
        }

        // -------------------------------------------------
        // Step 3: Initialize distances
        // -------------------------------------------------
        vector<int> dist(vertices, INF);

        // Distance from source to itself is 0
        dist[source] = 0;

        // -------------------------------------------------
        // Step 4: Relax edges in Topological Order
        // -------------------------------------------------
        while (!topoStack.empty()) {

            int node = topoStack.top();
            topoStack.pop();

            // If this node is unreachable from source,
            // we cannot use it to update other nodes.
            if (dist[node] == INF) {
                continue;
            }

            for (auto& edge : adj[node]) {

                int neighbour = edge.first;
                int wt = edge.second;

                // Relax the edge for maximum distance
                if (dist[node] + wt > dist[neighbour]) {
                    dist[neighbour] = dist[node] + wt;
                }
            }
        }

        return dist;
    }
};
