#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count = 0;

    void dfs(int node, int parent, vector<vector<pair<int, int>>>& adj, vector<bool>& visited) {
        visited[node] = true;
        
        for (auto &p : adj[node]) {
    int child = p.first;
    int sign  = p.second;

    if (!visited[child]) {
        count += sign;
        dfs(child, node, adj, visited);
    }
}
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        
        // sign = 1 means original direction is from u -> v (might need to reverse)
        // sign = 0 means v -> u (already towards 0 direction if we go correctly)
        for (auto& connection : connections) {
            int u = connection[0];
            int v = connection[1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0}); // reverse edge v -> u with sign 0
        }
        
        vector<bool> visited(n, false);
        dfs(0, -1, adj, visited);
        return count;
    }
};

int main() {
    Solution sol;

    int n = 6;
    vector<vector<int>> connections = {
        {0,1},
        {1,3},
        {2,3},
        {4,0},
        {4,5}
    };

    int ans = sol.minReorder(n, connections);
    cout << "Minimum roads to reorder: " << ans << endl;  // Expected: 3

    return 0;
}
