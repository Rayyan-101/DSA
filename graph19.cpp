#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> rankv;   // renamed from rank to avoid conflict with std::rank in some compilers

    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);   // path compression
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
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        rankv.assign(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        // attach original indices to queries
        for (int i = 0; i < (int)queries.size(); i++) {
            queries[i].push_back(i);  // queries[i] = {u, v, limit, original_index}
        }

        auto lambda = [&](vector<int>& v1, vector<int>& v2) {
            return v1[2] < v2[2];     // sort by weight / limit
        };

        sort(edgeList.begin(), edgeList.end(), lambda);  // sort edges by weight
        sort(queries.begin(),  queries.end(),  lambda);  // sort queries by limit

        vector<bool> result(queries.size());
        int j = 0;   // pointer on edgeList

        for (vector<int>& query : queries) {
            int u   = query[0];
            int v   = query[1];
            int w   = query[2];
            int idx = query[3];

            // union all edges whose weight < current query limit
            while (j < (int)edgeList.size() && edgeList[j][2] < w) {
                Union(edgeList[j][0], edgeList[j][1]);
                j++;
            }

            result[idx] = (find(u) == find(v));
        }

    }
};

int main() {
    Solution sol;

    int n = 5;
    vector<vector<int>> edgeList = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 3},
        {2, 3, 5},
        {3, 4, 6}
    };

    vector<vector<int>> queries = {
        {0, 1, 3},  // path 0-1 with edges < 3?  edge 0-1 has weight 2 -> true
        {0, 3, 5},  // path 0-3 with edges < 5?  needs 0-2(4) and 2-3(5) but 5 !< 5 -> false
        {0, 4, 7}   // path 0-4 with edges < 7?  0-2(4),2-3(5),3-4(6) all < 7 -> true
    };

    vector<bool> ans = sol.distanceLimitedPathsExist(n, edgeList, queries);

    cout << "Results:\n";
    for (bool x : ans) {
        cout << (x ? "true" : "false") << "\n";
    }

    return 0;
}
