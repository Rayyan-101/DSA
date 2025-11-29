#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSimilar(string &s1, string &s2) {
        int n = s1.length();
        int diff = 0;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i])
                diff++;
        }
        // Two strings are similar if they are equal or differ at exactly 2 positions
        return diff == 2 || diff == 0;
    }
    
    void DFS(int u, unordered_map<int, vector<int>> &adj, vector<bool>& visited) {
        visited[u] = true;
        
        for (int v : adj[u]) {
            if (!visited[v])
                DFS(v, adj, visited);
        }
    }
    
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        
        // Build graph: connect indices i, j if strs[i] and strs[j] are similar
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSimilar(strs[i], strs[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<bool> visited(n, false);
        int count = 0;
        
        // Count connected components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                DFS(i, adj, visited);
                count++;
            }
        }
        
        return count;
    }
};

int main() {
    Solution sol;

    vector<string> strs1 = {"tars","rats","arts","star"};
    cout << "Number of similar groups (example 1): "
         << sol.numSimilarGroups(strs1) << endl;  // Expected: 2

    vector<string> strs2 = {"omv","ovm"};
    cout << "Number of similar groups (example 2): "
         << sol.numSimilarGroups(strs2) << endl;  // Expected: 1

    return 0;
}
