#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int result;

    void dfs(int u, vector<int>& edges, vector<bool> &visited,
             vector<int>& dist, vector<bool> &inRecursion) {

        if (u != -1) {
            visited[u] = true;
            inRecursion[u] = true;

            int v = edges[u];

            if (v != -1 && !visited[v]) {
                dist[v] = dist[u] + 1;
                dfs(v, edges, visited, dist, inRecursion);
            } 
            else if (v != -1 && inRecursion[v] == true) { // found a cycle
                // length of cycle = dist[u] - dist[v] + 1
                result = max(result, dist[u] - dist[v] + 1);
            }

            inRecursion[u] = false;
        }
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        result = -1;

        vector<bool> visited(n, false);
        vector<int> dist(n, 0);
        vector<bool> inRecursion(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dist[i] = 1;         // starting depth for this DFS tree
                dfs(i, edges, visited, dist, inRecursion);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> edges1 = {3,3,4,2,3};
    cout << "Longest cycle length (example 1): " 
         << sol.longestCycle(edges1) << endl;  // Expected: 3

    vector<int> edges2 = {2,-1,3,1};
    cout << "Longest cycle length (example 2): " 
         << sol.longestCycle(edges2) << endl;  // Expected: -1 (no cycle)

    return 0;
}
