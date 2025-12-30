#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> indegree(n, false);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            indegree[v] = true;  // mark incoming node
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (!indegree[i])
                result.push_back(i);
        }

        return result;
    }
};

int main() {
    Solution sol;

    int n = 6;
    vector<vector<int>> edges = {
        {0,1},
        {0,2},
        {2,5},
        {3,4},
        {4,2}
    };

    vector<int> ans = sol.findSmallestSetOfVertices(n, edges);

    cout << "Smallest set of vertices: ";
    for (int x : ans) cout << x << " ";
    cout << endl;


    return 0;
}
