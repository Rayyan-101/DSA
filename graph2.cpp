#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;

    void dfs(vector<vector<int>>& stones, int index, vector<bool>& visited) {
        visited[index] = true;

        for (int i = 0; i < n; i++) {
            // If not visited and shares row or column
            if (!visited[i] && 
                (stones[i][0] == stones[index][0] || stones[i][1] == stones[index][1])) {
                dfs(stones, i, visited);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        vector<bool> visited(n, false);

        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(stones, i, visited);
                components++;
            }
        }

        return n - components;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> stones = {
        {0,0}, {0,1}, {1,0}, {1,2}, {2,1}, {2,2}
    };

    cout << "Maximum stones removed = "
         << sol.removeStones(stones) << endl;

    return 0;
}
