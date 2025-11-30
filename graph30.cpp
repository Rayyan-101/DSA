#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);
        
        // Build graph (0-based indexing)
        for (auto &vec : relations) {
            int u = vec[0] - 1; // prerequisite
            int v = vec[1] - 1; // dependent
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> que;
        vector<int> maxTime(n, 0); // maxTime[i] = earliest finish time of course i
        
        // Push all courses with no prerequisites
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                que.push(i);
                maxTime[i] = time[i]; // they can start immediately
            }
        }
        
        // Kahn's algorithm (topological BFS)
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            
            for (int v : adj[u]) {
                // Finishing time of v depends on max of all its prerequisites
                maxTime[v] = max(maxTime[v], maxTime[u] + time[v]);
                indegree[v]--;
                if (indegree[v] == 0) {
                    que.push(v);
                }
            }
        }
        
        return *max_element(maxTime.begin(), maxTime.end());
    }
};

int main() {
    Solution sol;

    int n = 3;
    vector<vector<int>> relations = {
        {1, 3},
        {2, 3}
    };
    vector<int> time = {3, 2, 5}; // course 1->3, 2->2, 3->5

    cout << "Minimum time to finish all courses: "
         << sol.minimumTime(n, relations, time) << endl;
    // Explanation:
    // course 1: 3
    // course 2: 2 (parallel)
    // course 3: can start after max(3,2) = 3, so 3 + 5 = 8
    // Answer: 8

    return 0;
}
