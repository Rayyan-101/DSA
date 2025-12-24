#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        
        queue<pair<int, int>> que;
        que.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+'; // marking entrance as visited
        
        int steps = 0;
        
        while (!que.empty()) {
            int size = que.size();
            
            while (size--) {
                pair<int, int> temp = que.front();
                que.pop();
                
                // If it's not the entrance and it's on the boundary, it's an exit
                if (temp != make_pair(entrance[0], entrance[1]) && 
                    (temp.first == 0 || temp.first == m - 1 || 
                     temp.second == 0 || temp.second == n - 1)) {
                    return steps;
                }
                
                for (auto &dir : directions) {
                    int i = temp.first  + dir[0];
                    int j = temp.second + dir[1];

                    if (i >= 0 && i < m && j >= 0 && j < n && maze[i][j] != '+') {
                        que.push({i, j});
                        maze[i][j] = '+'; // mark as visited
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};

int main() {
    // Example maze:
    // + . + +
    // . . . +
    // + . . .
    vector<vector<char>> maze = {
        {'+','.','+','+'},
        {'.','.','.','+'},
        {'+','.','.','.'}
    };

    vector<int> entrance = {1, 0}; // row 1, col 0

    Solution sol;
    int ans = sol.nearestExit(maze, entrance);

    cout << "Nearest exit steps: " << ans << endl;  // Expected output: 2

    return 0;
}
