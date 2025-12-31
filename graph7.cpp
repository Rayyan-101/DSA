#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int target;

    void dfs(vector<vector<int>>& adj, int start, vector<int>& temp, vector<vector<int>>& result) {
        if (start == target) {
            result.push_back(temp);
            return;
        }
        
        for (int x : adj[start]) {
            temp.push_back(x);
            dfs(adj, x, temp, result);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> temp;

        target = graph.size() - 1;
        temp.push_back(0);  
        
        dfs(graph, 0, temp, result);
        
        return result;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> graph = {
        {1, 2},
        {3},
        {3},
        {}
    };

    vector<vector<int>> paths = sol.allPathsSourceTarget(graph);

    cout << "All paths from source to target:\n";
    for (auto &path : paths) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << "\n";
    }

    // Expected Output:
    // 0 1 3
    // 0 2 3

    return 0;
}
