class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rSize = mat.size();
        int cSize = mat[0].size();
        vector<int> r(rSize, 0);
        vector<int> c(cSize, 0);

        for(int i = 0; i < rSize; i++){
            for(int j = 0; j < cSize; j++){
                if(mat[i][j] == 1){
                    r[i]++;
                    c[j]++;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < rSize; i++){
            for(int j = 0; j < cSize; j++){
                if(mat[i][j] == 1 && r[i] == 1 && c[j] == 1){
                    ans++;
                }
            }
        }

        return ans;
    }
};
