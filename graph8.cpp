#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int DFS(unordered_map<int, vector<int>> &adj, int curr, int parent, vector<bool>& hasApple) {
        int time = 0;
        
        for (int child : adj[curr]) {
            if (child == parent)
                continue;
            
            int childTime = DFS(adj, child, curr, hasApple);
            
            // If child subtree has apples or the child itself has an apple,
            // we need to go to that child and come back => +2 edges
            if (childTime > 0 || hasApple[child]) {
                time += 2 + childTime;
            }
        }
        
        return time;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> adj;
        
        for (auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return DFS(adj, 0, -1, hasApple);
    }
};

int main() {
    Solution sol;

    int n = 7;
    vector<vector<int>> edges = {
        {0,1}, {0,2}, {1,4}, {1,5}, {2,3}, {2,6}
    };
    vector<bool> hasApple = {false, false, true, false, true, true, false};

    int ans = sol.minTime(n, edges, hasApple);
    cout << "Minimum time to collect all apples: " << ans << endl;

    return 0;
}
