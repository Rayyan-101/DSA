#include <bits/stdc++.h>
using namespace std;

#define P pair<int, pair<int,int>>

vector<vector<int>> directions = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

int minimumObstacles(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> result(m, vector<int>(n, INT_MAX));
    result[0][0] = 0;

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, {0, 0}});  // {cost, {i, j}}

    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        int d = curr.first;
        int i = curr.second.first;
        int j = curr.second.second;

        // Early stop: once we pop (m-1, n-1), it's optimal
        if (i == m - 1 && j == n - 1)
            return d;

        // Explore 4 directions
        for (auto& dir : directions) {
            int x = i + dir[0];
            int y = j + dir[1];

            if (x < 0 || x >= m || y < 0 || y >= n)
                continue;

            int wt = (grid[x][y] == 1 ? 1 : 0);

            if (d + wt < result[x][y]) {
                result[x][y] = d + wt;
                pq.push({result[x][y], {x, y}});
            }
        }
    }

    return result[m - 1][n - 1];
}

// ----------------------------
//            MAIN
// ----------------------------

int main() {
    int m, n;
    cout << "Enter grid dimensions (m n): ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    cout << "Enter grid (0 for empty, 1 for obstacle):\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    int ans = minimumObstacles(grid);

    cout << "\nMinimum obstacles to remove = " << ans << endl;

    return 0;
}
