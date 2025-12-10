#include <bits/stdc++.h>
using namespace std;

#define P pair<int, int>

// Standard Dijkstra's algorithm
void dijkstra(int n, unordered_map<int, vector<P>>& adj, vector<int>& result, int S) {
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, S});

    fill(result.begin(), result.end(), INT_MAX);
    result[S] = 0;

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Explore neighbors
        for (auto& p : adj[node]) {
            int adjNode = p.first;
            int dist = p.second;

            if (d + dist < result[adjNode]) {
                result[adjNode] = d + dist;
                pq.push({d + dist, adjNode});
            }
        }
    }
}

// Determine city with fewest reachable neighbors
int getCityWithFewestReachable(int n, const vector<vector<int>>& shortestPathMatrix,
                               int distanceThreshold) {
    int cityWithFewestReachable = -1;
    int fewestReachableCount = INT_MAX;

    for (int i = 0; i < n; i++) {
        int reachableCount = 0;

        for (int j = 0; j < n; j++) {
            if (i != j && shortestPathMatrix[i][j] <= distanceThreshold) {
                reachableCount++;
            }
        }

        // Tie-breaking: choose the city with the **greatest index**
        if (reachableCount <= fewestReachableCount) {
            fewestReachableCount = reachableCount;
            cityWithFewestReachable = i;
        }
    }
    return cityWithFewestReachable;
}

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    unordered_map<int, vector<P>> adj;
    vector<vector<int>> shortestPathMatrix(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; i++)
        shortestPathMatrix[i][i] = 0;

    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Run Dijkstra for each city
    for (int i = 0; i < n; i++) {
        dijkstra(n, adj, shortestPathMatrix[i], i);
    }

    return getCityWithFewestReachable(n, shortestPathMatrix, distanceThreshold);
}


// ---------------------------
//            MAIN
// ---------------------------

int main() {
    int n, m, threshold;
    cout << "Enter number of cities (n), number of edges (m), and distance threshold: ";
    cin >> n >> m >> threshold;

    vector<vector<int>> edges(m, vector<int>(3));
    cout << "Enter edges: u v w\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int city = findTheCity(n, edges, threshold);
    cout << "City with fewest reachable neighbors within threshold = " << city << endl;

    return 0;
}
