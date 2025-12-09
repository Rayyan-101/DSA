#include <bits/stdc++.h>
using namespace std;

long long maximumImportance(int n, vector<vector<int>>& roads) {
    // n = number of cities (0 to n-1)

    vector<int> degree(n, 0);

    for (auto &vec : roads) {
        int u = vec[0];
        int v = vec[1];
        degree[u]++;
        degree[v]++;
    }

    // Sort degrees in ascending order
    sort(begin(degree), end(degree));

    long long value = 1;
    long long sum   = 0;

    for (int i = 0; i < n; i++) {
        sum += (long long)degree[i] * value;
        value++;
    }

    return sum;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> roads(m, vector<int>(2));

    for (int i = 0; i < m; i++) {
        cin >> roads[i][0] >> roads[i][1];
    }

    cout << maximumImportance(n, roads) << "\n";

    return 0;
}
