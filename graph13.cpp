#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(unordered_map<int, vector<pair<int, int>>> &adj, 
             int u, vector<bool>& visited, int &result) {
        
        visited[u] = true;
        
        for (auto &vec : adj[u]) {
            int v = vec.first;
            int c = vec.second;
            
            result = min(result, c);  // track min edge on all reachable paths
            
            if (!visited[v]) {
                dfs(adj, v, visited, result);
            }
        }
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for (auto &vec : roads) {
            int u = vec[0];
            int v = vec[1];
            int c = vec[2];
            
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }
        
        vector<bool> visited(n + 1, false);
        int result = INT_MAX;
        
        dfs(adj, 1, visited, result);
        
        return result;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> roads = {
        {1, 2, 9},
        {2, 3, 6},
        {2, 4, 5},
        {1, 4, 7}
    };
    int n = 4;

    int answer = sol.minScore(n, roads);
    cout << "Minimum score: " << answer << endl;
    // Expected output: 5

    return 0;
}
