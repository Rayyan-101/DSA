#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent;
    int components;

public: 
    DSU(int n) {
        parent.resize(n + 1);
        rankv.assign(n + 1, 0);
        components = n;
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]); // path compression
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;

        if (rankv[x_parent] > rankv[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rankv[x_parent] < rankv[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rankv[y_parent]++;
        }
        components--;
    }

    bool isSingle() {
        return components == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // Sort by type descending so type 3 (shared) edges come first
        auto lambda = [&](vector<int>& v1, vector<int>& v2) {
            return v1[0] > v2[0];
        };
        
        sort(edges.begin(), edges.end(), lambda);
        
        DSU Alice(n);
        DSU Bob(n);
        
        int addedEdge = 0;
        
        for (auto &edge: edges) {
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];
            
            if (type == 3) {
                bool add = false;
                
                if (Alice.find(u) != Alice.find(v)) {
                    Alice.Union(u, v);
                    add = true;
                }
                
                if (Bob.find(u) != Bob.find(v)) {
                    Bob.Union(u, v);
                    add = true;
                }
                
                if (add)
                    addedEdge++;
                
            } else if (type == 2) { // Bob only
                if (Bob.find(u) != Bob.find(v)) {
                    Bob.Union(u, v);
                    addedEdge++;
                }
            } else { // type == 1, Alice only
                if (Alice.find(u) != Alice.find(v)) {
                    Alice.Union(u, v);
                    addedEdge++;
                }
            }
        }
        
        if (Alice.isSingle() && Bob.isSingle()) {
            return (int)edges.size() - addedEdge;
        }
        
        return -1;
    }
};

int main() {
    Solution sol;

    int n = 4;
    vector<vector<int>> edges = {
        {3,1,2},
        {3,2,3},
        {1,1,3},
        {1,2,4},
        {1,1,2},
        {2,3,4}
    };

    int ans = sol.maxNumEdgesToRemove(n, edges);
    cout << "Maximum number of removable edges: " << ans << endl; 
    // Expected: 2

    return 0;
}
