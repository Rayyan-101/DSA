class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        // Code here
        int i = 0, j = -1;
        vector<int> sol;
        for(int k = 1;k<arr.size();k++)
        {
            if(arr[k] <= arr[i]){
                i = k;
            }
            else{
                if(j == -1  or arr[k]<=arr[j]){
                    j = k;
                }
                else if(arr[k] > arr[j]){
                    sol.push_back(arr[k]);
                    sol.push_back(arr[j]);
                    break;
                }
            }
        }
        if(sol.empty())return sol;
        for(int i = j;i>=0;i--){
            if(arr[i]<sol.back())sol.push_back(arr[i]);
            if(sol.size() == 3)break;
        }
        swap(sol[0], sol[2]);
        return sol;
    }
};
