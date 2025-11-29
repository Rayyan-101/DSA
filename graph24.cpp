#include <bits/stdc++.h>
using namespace std;

typedef pair<double, int> P;  // {probability, node}

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<int, double>>> adj;
        vector<double> result(n, 0.0);

        // Build adjacency list
        for (int i = 0; i < (int)edges.size(); i++) {
            int u       = edges[i][0];
            int v       = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        // Max-heap based on probability
        priority_queue<P> pq; // {prob, node}
        result[start] = 1.0;
        pq.push({1.0, start});

        while (!pq.empty()) {
            double curProb = pq.top().first;
            int curnode    = pq.top().second;
            pq.pop();

            // Optional small optimization: if this is already worse than stored, skip
            if (curProb < result[curnode]) continue;

            for (auto &child : adj[curnode]) {
                int nextNode   = child.first;
                double edgeProb = child.second;

                double newProb = curProb * edgeProb;
                if (result[nextNode] < newProb) {  // we want maximum probability
                    result[nextNode] = newProb;
                    pq.push({newProb, nextNode});
                }
            }
        }

        return result[end];
    }
};

int main() {
    Solution sol;

    int n = 3;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {0, 2}
    };
    vector<double> succProb = {0.5, 0.5, 0.2};
    int start = 0, end = 2;

    double ans = sol.maxProbability(n, edges, succProb, start, end);
    cout << fixed << setprecision(5);
    cout << "Maximum probability from " << start << " to " << end << " = " << ans << endl;
    // Expected: 0.25 (best path 0 -> 1 -> 2 with prob 0.5 * 0.5)

    return 0;
}
