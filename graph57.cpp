class Solution {
  public:
    void dfs(int node,vector<bool>&visited,vector<int>adj[]){
        visited[node]=true;
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,visited,adj);
            }
        }
    }
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        int edgeCount = edges.size();
        int components = 0;
        vector<int>adj[n];
        vector<bool>visited(n,false);
        if(edgeCount < n-1){
            return -1;
        }
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,adj);
                components++;
            }
        }
        
        return components-1;
        
        
    }
};
