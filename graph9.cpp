#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int result;
    
    int DFS(unordered_map<int, vector<int>> &adj, int curr, int parent, string& s) {
        int longest = 0;
        int second_longest = 0;
        
        for (int child : adj[curr]) {
            if (child == parent)
                continue;
            
            int child_longest_length = DFS(adj, child, curr, s);
            
            if (s[child] == s[curr])
                continue;
            
            // Maintain top two longest child chains
            if (child_longest_length > second_longest)
                second_longest = child_longest_length;
            
            if (second_longest > longest)
                swap(longest, second_longest);
        }
        
        // Best chain going *down* from this node (including itself)
        int koi_ek_acha = longest + 1; // include curr node
        
        int only_root_acha = 1; // just the node itself
        
        // Best path *through* this node using two child branches + curr
        int neeche_hi_milgaya_answer = longest + second_longest + 1;
        
        result = max({result, neeche_hi_milgaya_answer, koi_ek_acha, only_root_acha});
        
        // Return longest chain starting at curr and going down
        return max(koi_ek_acha, only_root_acha);
    }
    
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        result = 0;
        unordered_map<int, vector<int>> adj;
        
        // Build undirected tree
        for (int i = 1; i < n; i++) {
            int u = i;
            int v = parent[i];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        DFS(adj, 0, -1, s);
        
        return result;
    }
};

int main() {
    Solution sol;

    // Example 1:
    vector<int> parent1 = {-1, 0, 0, 1, 1, 2};
    string s1 = "abacbe";
    cout << "Longest path (example 1): " 
         << sol.longestPath(parent1, s1) << endl; // Expected: 3

    // Example 2:
    vector<int> parent2 = {-1, 0, 0, 0};
    string s2 = "aabc";
    cout << "Longest path (example 2): " 
         << sol.longestPath(parent2, s2) << endl; // Expected: 3

    return 0;
}
