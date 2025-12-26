#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, vector<int>>& adj, vector<int>& visited,
         stack<int>& st, bool& hasCycle) {
    
    visited[node] = 1; // visiting

    for (int& nbr : adj[node]) {
        if (visited[nbr] == 0) {
            dfs(nbr, adj, visited, st, hasCycle);
            if (hasCycle) return;
        } 
        else if (visited[nbr] == 1) {
            hasCycle = true;
            return;
        }
    }

    visited[node] = 2; // visited
    st.push(node);
}

vector<int> topoSort(vector<vector<int>>& edges, int n) {
    unordered_map<int, vector<int>> adj;
    vector<int> visited(n + 1, 0);
    bool hasCycle = false;
    stack<int> st;

    for (auto& e : edges) {
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            dfs(i, adj, visited, st, hasCycle);
            if (hasCycle) return {};
        }
    }

    vector<int> order;
    while (!st.empty()) {
        order.push_back(st.top());
        st.pop();
    }

    return order;
}

vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                vector<vector<int>>& colConditions) {
    
    vector<int> orderRows = topoSort(rowConditions, k);
    vector<int> orderCols = topoSort(colConditions, k);

    if (orderRows.empty() || orderCols.empty())
        return {};

    vector<vector<int>> matrix(k, vector<int>(k, 0));

    unordered_map<int, int> rowPos, colPos;

    // Store row positions
    for (int i = 0; i < k; i++) rowPos[orderRows[i]] = i;
    
    // Store col positions
    for (int i = 0; i < k; i++) colPos[orderCols[i]] = i;

    // Place each number 1..k at its (row, col)
    for (int num = 1; num <= k; num++) {
        int r = rowPos[num];
        int c = colPos[num];
        matrix[r][c] = num;
    }

    return matrix;
}



int main() {
    int k, r, c;
    cout << "Enter k (#elements), #rowConditions, #colConditions: ";
    cin >> k >> r >> c;

    vector<vector<int>> rowConditions(r, vector<int>(2));
    vector<vector<int>> colConditions(c, vector<int>(2));

    cout << "Enter row conditions (u v meaning u before v):\n";
    for (int i = 0; i < r; i++)
        cin >> rowConditions[i][0] >> rowConditions[i][1];

    cout << "Enter column conditions (u v meaning u before v):\n";
    for (int i = 0; i < c; i++)
        cin >> colConditions[i][0] >> colConditions[i][1];

    vector<vector<int>> result = buildMatrix(k, rowConditions, colConditions);

    if (result.empty()) {
        cout << "No valid matrix exists (cycle detected)\n";
        return 0;
    }

    cout << "\nConstructed Matrix:\n";
    for (auto& row : result) {
        for (int x : row)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}
