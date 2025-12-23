#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> P;

class Solution {
public:
    vector<vector<int>> directions{
        {1,1},{1,0},{0,1},{-1,-1},{-1,0},{0,-1},{1,-1},{-1,1}
    };

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (m == 0 || n == 0 || grid[0][0] != 0)
            return -1;

        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        while (!pq.empty()) {
            int d  = pq.top().first;
            int x  = pq.top().second.first;
            int y  = pq.top().second.second;
            pq.pop();

            if (d > dist[x][y]) continue;

            for (auto &dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if (isSafe(x_, y_) && grid[x_][y_] == 0 && d + 1 < dist[x_][y_]) {
                    dist[x_][y_] = d + 1;
                    pq.push({dist[x_][y_], {x_, y_}});
                }
            }
        }

        return dist[m-1][n-1] == INT_MAX ? -1 : dist[m-1][n-1] + 1;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {0,1},
        {1,0}
    };

    cout << "Shortest path length = "
         << sol.shortestPathBinaryMatrix(grid) << endl;

    return 0;
}
