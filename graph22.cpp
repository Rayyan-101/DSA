#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(unordered_map<string, vector<pair<string, double>>> &adj,
             const string &src, const string &dst,
             unordered_set<string> &visited,
             double product, double &ans) {
        
        if (visited.find(src) != visited.end())
            return;
        
        visited.insert(src);
        
        if (src == dst) {
            ans = product;
            return;
        }
        
        for (auto &p : adj[src]) {
            string v   = p.first;
            double val = p.second;
            if (visited.find(v) == visited.end()) {
                dfs(adj, v, dst, visited, product * val, ans);
            }
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        int n = equations.size();
        
        unordered_map<string, vector<pair<string, double>>> adj;
        
        // Build graph: u/v = val  =>  u->v (val), v->u (1/val)
        for (int i = 0; i < n; i++) {
            string u   = equations[i][0];
            string v   = equations[i][1];
            double val = values[i];
            
            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0 / val});
        }
        
        vector<double> result;
        
        for (auto &query : queries) {
            string src = query[0];
            string dst = query[1];
            
            double ans     = -1.0;
            double product = 1.0;
            
            // Only search if src exists in graph
            if (adj.find(src) != adj.end()) {
                unordered_set<string> visited;
                dfs(adj, src, dst, visited, product, ans);
            }
            
            result.push_back(ans);
        }
        
        return result;
    }
};

int main() {
    Solution sol;

    vector<vector<string>> equations = {{"a","b"}, {"b","c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {
        {"a","c"},
        {"b","a"},
        {"a","e"},
        {"a","a"},
        {"x","x"}
    };

    vector<double> ans = sol.calcEquation(equations, values, queries);

    cout.setf(ios::fixed);
    cout << setprecision(5);
    cout << "Results:\n";
    for (double x : ans) {
        cout << x << "\n";
    }
    // Expected (LeetCode example): [6.00000,0.50000,-1.00000,1.00000,-1.00000]

    return 0;
}
