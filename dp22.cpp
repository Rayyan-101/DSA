class Solution {
  public:
    int MOD = 1e9 + 7;

    int countSubsequences(string& s, int n) {
        // code here

        int m = s.size();

        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int i=0;i<=m;i++)
        dp[i][0] = 1;

        for(int i=m-1;i>=0;i--)
        {
            int num = s[i] - '0';

            for(int j=0;j<n;j++)
            {
                int take = dp[i+1][(j * 10 + num) % n];

                int skip = dp[i+1][j];

                dp[i][j] = (take + skip) % MOD;
            }
        }

        return dp[0][0] - 1;
        
    }
};
