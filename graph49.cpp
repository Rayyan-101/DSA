class Solution {
  public:
    int cntOnes(vector<vector<int>>& grid) {
        // code here
         int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        
        vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if (grid[i][j] == 1) {
                        vis[i][j] = true;
                        q.push({i, j});
                    }
                }
            }
        }
        
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < dir.size(); ++i) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if (nr >= 0 and nr < n and nc >= 0 and nc < m and grid[nr][nc] == 1 and !vis[nr][nc]) {
                    q.push({nr, nc});
                    vis[nr][nc] = true;
                }
            }
        }
        
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 and !vis[i][j])
                    cnt++;
            }
        }
        return cnt;
    }
};
