#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

class Solution {
public:
    void DFS(int u, unordered_set<int> &visited, unordered_map<int, vector<int>> &adj) {
        visited.insert(u);
        
        for (int v : adj[u]) {
            if (visited.find(v) == visited.end()) { // Not visited
                DFS(v, visited, adj);
            }
        }
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        
        unordered_map<int, vector<int>> adj;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                
                if (i == j) // same bomb
                    continue;
                
                LL x1 = bombs[i][0];
                LL y1 = bombs[i][1];
                LL r1 = bombs[i][2];
                
                LL x2 = bombs[j][0];
                LL y2 = bombs[j][1];
                // LL r2 = bombs[j][2]; // not needed
                
                LL distance = (x2 - x1) * (x2 - x1) + 
                              (y2 - y1) * (y2 - y1);
                
                if (r1 * r1 >= distance) {
                    adj[i].push_back(j);
                }
            }
        }
        
        int result = 0;
        unordered_set<int> visited;
        
        for (int i = 0; i < n; i++) {
            DFS(i, visited, adj);
            int count = visited.size();
            result = max(result, count);
            visited.clear();
        }
        
        return result;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> bombs = {
        {2, 1, 3},
        {6, 1, 4}
    };

    cout << "Maximum bombs detonated: "
         << sol.maximumDetonation(bombs) << endl;  

    return 0;
}
