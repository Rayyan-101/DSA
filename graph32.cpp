#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        // stop -> list of routes (indices) that pass through this stop
        unordered_map<int, vector<int>> adj;
        int R = routes.size();

        for (int route = 0; route < R; route++) {
            for (int stop : routes[route]) {
                adj[stop].push_back(route);
            }
        }

        // BFS over routes (buses)
        queue<int> que;
        vector<bool> visitedRoute(R, false);

        // Start from all routes that contain the source stop
        for (int route : adj[source]) {
            que.push(route);
            visitedRoute[route] = true;
        }

        int busCount = 1;
        while (!que.empty()) {
            int size = que.size();

            while (size--) {
                int route = que.front();
                que.pop();

                // For every stop on this route
                for (int stop : routes[route]) {
                    // If this stop is the target, we reached with busCount buses
                    if (stop == target) {
                        return busCount;
                    }

                    // From this stop, we can transfer to other routes
                    for (int nextRoute : adj[stop]) {
                        if (!visitedRoute[nextRoute]) {
                            visitedRoute[nextRoute] = true;
                            que.push(nextRoute);
                        }
                    }
                }
            }
            busCount++;
        }
        return -1;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> routes = {
        {1, 2, 7},
        {3, 6, 7}
    };
    int source = 1, target = 6;

    int ans = sol.numBusesToDestination(routes, source, target);
    cout << "Minimum number of buses: " << ans << endl;  // Expected: 2

    return 0;
}
