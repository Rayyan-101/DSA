#include <bits/stdc++.h>
using namespace std;

int findChampion(int n, vector<vector<int>>& edges) {
    vector<int> indegree(n, 0);

    for (vector<int>& edge : edges) {
        int u = edge[0];
        int v = edge[1];

        // u → v
        indegree[v]++;
    }

    int champ = -1;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            champ = i;
            count++;
            if (count > 1) return -1; // more than one possible champion
        }
    }

    return champ;
}

int main() {
    int n, m;
    cout << "Enter number of nodes (n) and edges (m): ";
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    cout << "Enter directed edges (u v meaning u -> v):\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    int champion = findChampion(n, edges);

    if (champion == -1)
        cout << "No unique champion exists.\n";
    else
        cout << "Champion node: " << champion << "\n";

    return 0;
}
