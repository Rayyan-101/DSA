#include <bits/stdc++.h>
using namespace std;

vector<int> countOfPairs(int n, int x, int y) {

    vector<vector<int>> grid(n+1, vector<int>(n+1, 100000));

    // Adjacent edges
    for(int j = 1; j < n; j++) {
        grid[j][j+1] = 1;
        grid[j+1][j] = 1;
    }

    // Special extra edge
    grid[x][y] = 1;
    grid[y][x] = 1;

    // Floyd–Warshall
    for(int via = 1; via <= n; via++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
            }
        }
    }

    // Count distances
    vector<int> result(n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i != j) {
                int d = grid[i][j];
                result[d - 1]++;
            }
        }
    }

    return result;
}

int main() {
    int n, x, y;
    cout << "Enter n, x, y: ";
    cin >> n >> x >> y;

    vector<int> ans = countOfPairs(n, x, y);

    cout << "Result: ";
    for(int v : ans) cout << v << " ";
    cout << endl;

    return 0;
}
