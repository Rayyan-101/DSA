#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n, INT_MAX);
        
        unordered_map<int, vector<pair<int, int>>> adj;
        
        // Build adjacency list: u -> (v, cost)
        for (vector<int> &vec : flights) {
            int u    = vec[0];
            int v    = vec[1];
            int cost = vec[2];
            adj[u].push_back({v, cost});
        }
        
        queue<pair<int, int>> que; // {node, cost_so_far}
        que.push({src, 0});
        distance[src] = 0;
        
        int level = 0; // number of edges used so far
        
        // We are allowed at most k stops -> at most k+1 edges
        while (!que.empty() && level <= k) {
            int N = que.size();
            
            // To avoid affecting other nodes in the same level,
            // we use a temp copy of distance
            vector<int> temp = distance;
            
            while (N--) {
                int u = que.front().first;
                int d = que.front().second;
                que.pop();
                
                for (pair<int, int> &P : adj[u]) {
                    int v    = P.first;
                    int cost = P.second;
                    
                    if (temp[v] > d + cost) {
                        temp[v] = d + cost;
                        que.push({v, d + cost});
                    }
                }
            }
            distance = temp;
            level++;
        }
        
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};

int main() {
    Solution sol;

    int n = 4;
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 3, 100},
        {0, 2, 500}
    };
    int src = 0, dst = 3, k = 1;

    int ans = sol.findCheapestPrice(n, flights, src, dst, k);
    cout << "Cheapest price: " << ans << endl;  

    k = 2;
    ans = sol.findCheapestPrice(n, flights, src, dst, k);
    cout << "Cheapest price with k=2: " << ans << endl;  // Expected: 300 (0 -> 1 -> 2 -> 3)

    return 0;
}
