class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
        int n=arr.size();
        stack<int>st;
        vector<int>nse(n,n);
        int total=0;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i]=st.top();
            }
            st.push(i);
        }
        for(int i=0;i<n;i++){
            total+=(nse[i]-i);
        }
        return total;
    }
};
