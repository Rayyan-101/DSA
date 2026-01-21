#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

// ---------------- Dijkstra ---------------- //

vector<int> dijkstra(unordered_map<int, vector<P>>& adj, int src, int n) {
    priority_queue<P, vector<P>, greater<P>> pq;

    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        ll currWt = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();

        if (visited[currNode]) continue;

        for (auto& nbr : adj[currNode]) {
            int nextNode = nbr.first;
            ll nextWt = nbr.second;

            if (dist[nextNode] > currWt + nextWt) {
                dist[nextNode] = currWt + nextWt;
                pq.push({currWt + nextWt, nextNode});
            }
        }

        visited[currNode] = true;
    }

    return dist;
}

// ---------------- Find Answer ---------------- //

vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
    int E = edges.size();

    unordered_map<int, vector<P>> adj;

    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> fromSrc = dijkstra(adj, 0, n);
    vector<int> fromDest = dijkstra(adj, n - 1, n);

    vector<bool> result(E, false);

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        ll distFromSrc = fromSrc[u];
        ll distFromDest = fromDest[v];

        if (distFromSrc + w + distFromDest == fromSrc[n - 1]) {
            result[i] = true;
        }

        distFromSrc = fromSrc[v];
        distFromDest = fromDest[u];

        if (distFromSrc + w + distFromDest == fromSrc[n - 1]) {
            result[i] = true;
        }
    }

    return result;
}

// ---------------- Main Function ---------------- //

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, E;
    cin >> n >> E;

    vector<vector<int>> edges(E, vector<int>(3));

    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    vector<bool> ans = findAnswer(n, edges);

    for (bool val : ans) {
        cout << (val ? "true" : "false") << " ";
    }
    cout << "\n";

    return 0;
}
