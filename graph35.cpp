#include <bits/stdc++.h>
using namespace std;

vector<int> parent, compCost;

// Find with path compression
int findSet(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findSet(parent[x]);
}

// Union by attaching vroot to uroot
void Union(int u, int v) {
    parent[v] = u;
}

vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {

    parent.resize(n);
    compCost.resize(n, -1);  // -1 means "no edges yet"

    for(int i = 0; i < n; i++)
        parent[i] = i;

    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        int ru = findSet(u);
        int rv = findSet(v);

        if (ru != rv) {
            // Merge rv into ru (or opposite — consistent only)
            Union(ru, rv);

            // Combine their costs
            if (compCost[ru] == -1 && compCost[rv] == -1)
                compCost[ru] = w;
            else if (compCost[ru] == -1)
                compCost[ru] = compCost[rv] & w;
            else if (compCost[rv] == -1)
                compCost[ru] &= w;
            else
                compCost[ru] = (compCost[ru] & compCost[rv] & w);
        }
        else {
            // Already same component → update cost by AND-ing w
            int root = ru;
            if (compCost[root] == -1)
                compCost[root] = w;
            else
                compCost[root] &= w;
        }
    }

    // Answer queries
    vector<int> res;
    for (auto &q : query) {
        int s = q[0];
        int t = q[1];

        if (s == t) {
            res.push_back(0);
            continue;
        }

        int rs = findSet(s);
        int rt = findSet(t);

        if (rs != rt) 
            res.push_back(-1);
        else 
            res.push_back(compCost[rs]);
    }
    return res;
}



int main() {
    int n, m, q;
    cout << "Enter number of nodes, edges, queries: ";
    cin >> n >> m >> q;

    vector<vector<int>> edges(m, vector<int>(3));
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < m; i++)
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];

    vector<vector<int>> queries(q, vector<int>(2));
    cout << "Enter queries (s t):\n";
    for (int i = 0; i < q; i++)
        cin >> queries[i][0] >> queries[i][1];

    vector<int> ans = minimumCost(n, edges, queries);

    cout << "Result:\n";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
