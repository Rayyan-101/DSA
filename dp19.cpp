class Solution {
public:
    int n;
    int solve(int person,int idx,int M,vector<int>& piles,vector<vector<vector<int>>> &dp){
        if(idx>=n) return 0;

        if(dp[person][idx][M]!=-1) return dp[person][idx][M];

        int sum=0;
        int result=(person==1?INT_MIN:INT_MAX);

        for(int i=1;i<=min(2*M,n-idx);i++){
            sum+=piles[i+idx-1];

            if(person==1){
                result=max(result,sum+solve(0,idx+i,max(M,i),piles,dp));
            }else{
                result=min(result,solve(1,idx+i,max(M,i),piles,dp));
            }
        }
        return dp[person][idx][M]= result;
    }
    int stoneGameII(vector<int>& piles) {
        int idx=0;
        int person=1;
        n=piles.size();
        int M=1;
        vector<vector<vector<int>>> dp(2,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        return solve(person,idx,M,piles,dp);
    }
};
