#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        // Reverse graph
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        queue<int> que;

        // Build reversed graph and indegree
        for (int u = 0; u < V; u++) {
            for (int v : graph[u]) {
                adj[v].push_back(u);  // reverse edge v -> u
                indegree[u]++;        // original indegree
            }
        }

        // Push all nodes with indegree 0 (terminal nodes in original graph)
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }

        vector<bool> safe(V, false);

        // Kahn's algorithm on reversed graph
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            safe[u] = true;

            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        vector<int> safeNodes;
       
        }
        // They are already in sorted order because we iterate i from 0..V-1
        return safeNodes;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> graph = {
        {1,2},
        {2,3},
        {5},
        {0},
        {5},
        {},
        {}
    };

    vector<int> res = sol.eventualSafeNodes(graph);

    cout << "Eventual safe nodes: ";
    for (int x : res) cout << x << " ";
    cout << endl;
    // Expected: 2 4 5 6

    return 0;
}
