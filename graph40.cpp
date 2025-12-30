#include <bits/stdc++.h>
using namespace std;

void DFS(int ancestor,
         unordered_map<int, vector<int>>& adj,
         int currNode,
         vector<vector<int>>& result,
         vector<vector<bool>>& visited)
{
    for (int ngbr : adj[currNode]) {

        // Prevent duplicate ancestor insertion
        if (!visited[ancestor][ngbr]) {
            visited[ancestor][ngbr] = true;
            result[ngbr].push_back(ancestor);
            DFS(ancestor, adj, ngbr, result, visited);
        }
    }
}

vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<vector<int>> result(n);
    unordered_map<int, vector<int>> adj;

    for (auto& vec : edges) {
        int u = vec[0];
        int v = vec[1];
        adj[u].push_back(v); // u -> v
    }

    vector<vector<bool>> visited(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        DFS(i, adj, i, result, visited);
    }

    for (int i = 0; i < n; i++) {
        sort(result[i].begin(), result[i].end());
    }

    return result;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<vector<int>> ans = getAncestors(n, edges);

    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": ";
        for (int x : ans[i]) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
