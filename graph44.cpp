#include <bits/stdc++.h>
using namespace std;

#define P pair<int, int>

unordered_map<int, vector<P>> adj;  // Global adjacency list

// Dijkstra from node 0 → n-1
int dijkstra(int n) {
    vector<int> result(n, INT_MAX);
    result[0] = 0;

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 0});  // {distance, node}

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (node == n - 1)
            return result[n - 1];

        if (d > result[node])
            continue;

        for (P& p : adj[node]) {
            int adjNode = p.first;
            int dist = p.second;

            if (d + dist < result[adjNode]) {
                result[adjNode] = d + dist;
                pq.push({d + dist, adjNode});
            }
        }
    }
    return result[n - 1];
}

vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    vector<int> result;

    // Initialize the base graph: edges i → i+1
    for (int i = 0; i < n - 1; i++)
        adj[i].push_back({i + 1, 1});

    // Process each query
    for (auto& q : queries) {
        int u = q[0];
        int v = q[1];

        adj[u].push_back({v, 1});  // Add directed edge u → v

        int d = dijkstra(n);       // Compute shortest path 0 → n-1
        result.push_back(d);
    }

    return result;
}

// ----------------------------------
//               MAIN
// ----------------------------------

int main() {
    int n, q;
    cout << "Enter n (nodes) and number of queries: ";
    cin >> n >> q;

    vector<vector<int>> queries(q, vector<int>(2));

    cout << "Enter queries (u v meaning add edge u -> v):\n";
    for (int i = 0; i < q; i++)
        cin >> queries[i][0] >> queries[i][1];

    vector<int> ans = shortestDistanceAfterQueries(n, queries);

    cout << "\nShortest distance from 0 → " << n - 1 << " after each query:\n";
    for (int d : ans)
        cout << d << " ";
    cout << endl;

    return 0;
}
