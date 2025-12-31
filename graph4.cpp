#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(unordered_map<int, vector<int>>& mp, int node, int dest, vector<bool>& visited) {
        if (node == dest)
            return true;
        
        if (visited[node])
            return false;
        
        visited[node] = true;
        
        for (int nei : mp[node]) {
            if (check(mp, nei, dest, visited))
                return true;
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination)
            return true;
        
        unordered_map<int, vector<int>> mp;
        
        for (vector<int> &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        
        vector<bool> visited(n, false);
        return check(mp, source, destination, visited);
    }
};

int main() {
    Solution sol;

    int n = 6;
    vector<vector<int>> edges = {
        {0,1}, {0,2}, {3,5}, {5,4}, {4,3}
    };
    int source = 0;
    int destination = 5;

    bool ans = sol.validPath(n, edges, source, destination);
    cout << (ans ? "Path exists" : "No path") << endl;  // Expected: No path

    n = 3;
    edges = {{0,1}, {1,2}};
    source = 0;
    destination = 2;

    ans = sol.validPath(n, edges, source, destination);
    cout << (ans ? "Path exists" : "No path") << endl;  // Expected: Path exists

    return 0;
}
