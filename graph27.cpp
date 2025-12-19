#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        vector<vector<bool>> connected(n, vector<bool>(n, false));
        
        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            
            degree[u]++;
            degree[v]++;
            
            connected[u][v] = true;
            connected[v][u] = true;
        }
        
        int maxRank = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = degree[i] + degree[j];
                
                // if there is a direct road between i and j, subtract 1
                if (connected[i][j]) {
                    rank -= 1;
                }
                
                maxRank = max(maxRank, rank);
            }
        }
        
        return maxRank;
    }
};

int main() {
    Solution sol;

    int n = 4;
    vector<vector<int>> roads = {
        {0,1},
        {0,3},
        {1,2},
        {1,3}
    };

    int ans = sol.maximalNetworkRank(n, roads);
    cout << "Maximal network rank: " << ans << endl;

    return 0;
}
