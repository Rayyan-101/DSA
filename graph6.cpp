#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(unordered_map<int, vector<int>> &adj, int node, vector<int>& color) {
        queue<int> que;
        
        que.push(node);
        color[node] = 1;  // assign first color
        
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            
            for (int &v : adj[u]) {
                if (color[v] == color[u])
                    return false;  // same color on both ends -> not bipartite
                
                if (color[v] == -1) { // not colored yet
                    color[v] = 1 - color[u];
                    que.push(v);
                }
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> adj;
        
        for (vector<int> &vec : dislikes) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> color(n + 1, -1); // 1-based indexing
        
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {  // not visited
                if (!isBipartite(adj, i, color))
                    return false;
            }
        }
        
        return true;
    }
};

int main() {
    Solution sol;

    int n1 = 4;
    vector<vector<int>> dislikes1 = {{1,2}, {1,3}, {2,4}};
    cout << (sol.possibleBipartition(n1, dislikes1) ? "true" : "false") << endl;
    // Expected: true

    int n2 = 3;
    vector<vector<int>> dislikes2 = {{1,2}, {1,3}, {2,3}};
    cout << (sol.possibleBipartition(n2, dislikes2) ? "true" : "false") << endl;
    // Expected: false

    int n3 = 5;
    vector<vector<int>> dislikes3 = {{1,2},{2,3},{3,4},{4,5},{1,5}};
    cout << (sol.possibleBipartition(n3, dislikes3) ? "true" : "false") << endl;
    // Example extra test

    return 0;
}
