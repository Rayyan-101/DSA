class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        // Code here
        int m = a.size();
        int n = b.size();
        
        int i = 0;
        int j = 0;
        int sum1 = 0;
        int sum2 = 0;
        
        int totalSum = 0;
        
        while (i < m && j < n) {
            
            if (a[i] < b[j]) {
                sum1 += a[i++];
            } else if (a[i] > b[j]) {
                sum2 += b[j++];
            } else {
                totalSum += max(sum1, sum2) + a[i];
                sum1 = 0;
                sum2 = 0;
                i++;
                j++;
            }
        }
        
        while (i < m) sum1 += a[i++];
        while (j < n) sum2 += b[j++];
        
        totalSum += max(sum1, sum2);
        
        return totalSum;
    }
};
