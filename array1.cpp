class Solution {
  public:
    bool isPalindrome(int arr){
        string s=to_string(arr);
        int start=0;
        int end=s.size()-1;
        
        bool flag=true;
        
        while(start<end){
            if(s[start]!=s[end]){
                flag=false;
                break;
            }
            start++;
            end--;
        }
        return flag;
    }
  
    bool isPalinArray(vector<int> &arr) {
        // code here
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(!isPalindrome(arr[i])){
                return 0;
            }
        }
        return 1;
    }
};
