class Solution {
  public:
    vector<vector<int>> dp;
    int solve(int i,vector<int>& arr,int status){
        if(dp[i][status] != INT_MAX){
            return dp[i][status];
        }
        if(i >= arr.size()){
            return dp[i][status] = 0;
        }
        if(i == 0){
            //change.
            int a = 0 + solve(i+1,arr,1);
            //no change.
            int b = 0 + solve(i+1,arr,0);
            return max(a,b);
       }
        else{
            if(status == 0){
                //change.
                int a = abs(1-arr[i-1])+solve(i+1,arr,1);
                //no change.
                int b = abs(arr[i]-arr[i-1])+solve(i+1,arr,0);
                return dp[i][status] = max(a,b);
            }
            if(status == 1){
                //change.
                int a = abs(1-1)+solve(i+1,arr,1);
                //no change.
                int b = abs(arr[i]-1)+solve(i+1,arr,0);
                return dp[i][status] = max(a,b);
            }
        }
    }
    int maxDiffSum(vector<int>& arr) {
        //apply take or not take.
        int n = arr.size();
        dp.assign(n+2,vector<int>(3,INT_MAX));
        int i = 0;
        int status = 0;// status is for whether the previous index had been changed to 1 or not.
        return solve(i,arr,status);
    }
};
