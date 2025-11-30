#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P; // {node, mask}

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n <= 1) return 0;

        // BFS queue: (current node, bitmask of visited nodes)
        queue<P> que;

        // Visited states: (node, mask)
        set<P> vis;
        // Alternative faster option:
        // int maxMask = 1 << n;
        // vector<vector<bool>> vis(n, vector<bool>(maxMask, false));

        int allVisitedState = (1 << n) - 1; // all bits set => all nodes visited

        // Multi-source BFS: start from every node
        for (int i = 0; i < n; i++) {
            int maskValue = (1 << i);
            que.push({i, maskValue});
            vis.insert({i, maskValue});
            // vis[i][maskValue] = true; // if using 2D visited array
        }

        int result = 0;

        // BFS
        while (!que.empty()) {
            int sz = que.size();
            result++;

            while (sz--) {
                auto curr = que.front();
                que.pop();

                int currNode = curr.first;
                int currMask = curr.second;

                for (int adjNode : graph[currNode]) {
                    int nextMask = currMask | (1 << adjNode);

                    if (nextMask == allVisitedState) {
                        return result;
                    }

                    P state = {adjNode, nextMask};
                    if (vis.find(state) == vis.end()) {
                        vis.insert(state);
                        que.push(state);
                        // if (!vis[adjNode][nextMask]) { vis[adjNode][nextMask] = true; que.push({adjNode, nextMask}); }
                    }
                }
            }
        }

        return -1; // shouldn't happen for connected graphs
    }
};

int main() {
    Solution sol;

    vector<vector<int>> graph = {
        {1,2,3},  // 0
        {0},      // 1
        {0},      // 2
        {0}       // 3
    };

    cout << "Shortest path length visiting all nodes: "
         << sol.shortestPathLength(graph) << endl;  // Expected: 4

    return 0;
}
