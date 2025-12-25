#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;

    void dfs(vector<int>& edges, int startNode, vector<int>& dist_node, vector<bool>& visited) {
        visited[startNode] = true;
        
        int v = edges[startNode];
        
        if (v != -1 && !visited[v]) {
            visited[v] = true;
            dist_node[v] = 1 + dist_node[startNode];
            dfs(edges, v, dist_node, visited);
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();
        
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);
        vector<bool> visited1(n, false);
        vector<bool> visited2(n, false);
        
        dist1[node1] = 0;
        dist2[node2] = 0;
        
        dfs(edges, node1, dist1, visited1);
        dfs(edges, node2, dist2, visited2);
        
        int minDistNode = -1;
        int minDistTillNow = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            if (dist1[i] == INT_MAX || dist2[i] == INT_MAX)
                continue;  
            
            int maxD = max(dist1[i], dist2[i]);
            
            if (maxD < minDistTillNow) {
                minDistNode = i;
                minDistTillNow = maxD;
            }
        }

        return minDistNode;
    }
};

int main() {
    Solution sol;

    vector<int> edges = {2,2,3,-1};
    int node1 = 0;
    int node2 = 1;

    int ans = sol.closestMeetingNode(edges, node1, node2);
    cout << "Closest meeting node: " << ans << endl;  

    return 0;
}
