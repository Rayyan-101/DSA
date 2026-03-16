class Solution {
    int dfs(Node *root, int sum, int k, map<int,int>&mp)
    {
        if(!root) return 0;
        sum += root->data;
        int res = mp[sum - k];
        
        mp[sum]++;
        if(root->left) res += dfs(root->left, sum, k, mp);
        if(root->right) res += dfs(root->right, sum, k, mp);
        mp[sum]--;
        return res;
    }
  public:
    int countAllPaths(Node *root, int k) {
        // code here
        map<int, int>mp;
        mp[0] = 1;
        
        int sum = 0;
        return dfs(root, sum, k, mp);
    }
};
