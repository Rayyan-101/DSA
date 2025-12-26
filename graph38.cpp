#include <bits/stdc++.h>
using namespace std;

int countSteps(int ringIndex, int i, int n) {
    int dist = abs(i - ringIndex);
    int wrapAround = n - dist;
    return min(dist, wrapAround);
}

int findRotateSteps(string ring, string key) {
    int n = ring.length();
    int m = key.length();

    // Precompute indices for each character in ring
    unordered_map<char, vector<int>> adj;
    for (int i = 0; i < n; i++) {
        adj[ring[i]].push_back(i);
    }

    // Min-heap: {steps, ringIndex, keyIndex}
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, 0, 0});  // starting at index 0, key index 0

    set<pair<int, int>> visited;  // {ringIndex, keyIndex}

    int totalSteps = 0;

    while (!pq.empty()) {
        auto vec = pq.top();
        pq.pop();

        totalSteps = vec[0];
        int ringIndex = vec[1];
        int keyIndex = vec[2];

        // Finished spelling key
        if (keyIndex == m)
            break;

        // Skip visited states
        if (visited.count({ringIndex, keyIndex}))
            continue;

        visited.insert({ringIndex, keyIndex});

        // Try all positions for current key character
        for (int nextIndex : adj[key[keyIndex]]) {
            int stepsToRotate = countSteps(ringIndex, nextIndex, n);
            pq.push({totalSteps + stepsToRotate, nextIndex, keyIndex + 1});
        }
    }

    return totalSteps + m;  
}

int main() {
    string ring, key;
    cin >> ring >> key;

    cout << findRotateSteps(ring, key) << "\n";

    return 0;
}
