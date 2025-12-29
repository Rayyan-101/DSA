#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void dfs(vector<vector<int>>& rooms, int u, vector<bool>& visited) {
        visited[u] = true;
        
        for (int node : rooms[u]) {
            if (!visited[node])
                dfs(rooms, node, visited);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);

        // Start DFS from room 0
        dfs(rooms, 0, visited);
        
        for (bool x : visited) {
            if (!x) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> rooms1 = {
        {1},
        {2},
        {3},
        {}
    };

    cout << (sol.canVisitAllRooms(rooms1) ? "All rooms can be visited" 
                                          : "Cannot visit all rooms") << endl;
    // Expected: All rooms can be visited

    vector<vector<int>> rooms2 = {
        {1,3},
        {3,0,1},
        {2},
        {0}
    };

    cout << (sol.canVisitAllRooms(rooms2) ? "All rooms can be visited" 
                                          : "Cannot visit all rooms") << endl;
    // Expected: Cannot visit all rooms

    return 0;
}
