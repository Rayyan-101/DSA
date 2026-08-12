class Solution {
  public:
    vector<int> findWays(vector<vector<int>>& grid) {
        // code here
        int n  = grid.size() , m = grid[0].size();
        vector<int>mval(m , 0);
        vector<long long > tot(m , 0);
        mval[0] = grid[0][0];
        tot[0] =1;
        for(int j = 1 ; j<m ; j++){
            if(grid[0][j-1] !=2){
                mval[j] = mval[j-1] + grid[0][j];
                tot[j] = tot[j-1];
            }else{
                 break;
            }
        }
        // for(auto j: mval)cout<<j<<" ";
        //     cout<<endl;
        const int md = 1e9 + 7;
        for(int i = 1 ; i<n ; i++){
            vector<int>cval(m , 0);
            vector<long long>temp(m , 0);
            if(grid[i-1][0] !=1){
                if(mval[0])cval[0] = mval[0] + grid[i][0];
                temp[0] = tot[0];
            }
            for(int j = 1 ; j<m ; j++){
                if(grid[i-1][j] == 1 && grid[i][j-1] == 2)continue;
                if(grid[i-1][j] == 1){
                    cval[j] = cval[j-1] + grid[i][j];
                    temp[j] = temp[j-1];
                }else if(grid[i][j-1] == 2){
                    cval[j] = mval[j] + grid[i][j];
                    temp[j] = tot[j];
                }else{
                    temp[j] = (tot[j] + temp[j-1])%md;
                    if( mval[j] > cval[j-1]) cval[j] = mval[j] + grid[i][j];
                    else if(cval[j-1] > mval[j]) cval[j] = cval[j-1] + grid[i][j];
                    else cval[j] = mval[j] + grid[i][j];
                }
                if(cval[j] == grid[i][j])cval[j] = 0;
            }
            swap(temp, tot);
            swap(cval , mval);
            // for(auto j: mval)cout<<j<<" ";
            // cout<<endl;
        }
        return {tot.back() , mval.back()};
        
    }
};
