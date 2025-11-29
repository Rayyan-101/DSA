int target;
    void dfs(vector<vector<int>>& adj, int start, vector<int>& temp, vector<vector<int>>& result ) {
        if(start == target) {
            result.push_back(temp);
            return;
        }
        
        for(int &x : adj[start]) {
            temp.push_back(x);
            dfs(adj, x, temp, result);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> temp;
        target = graph.size()-1;
        temp.push_back(0);
        dfs(graph, 0, temp, result);
        
        return result;