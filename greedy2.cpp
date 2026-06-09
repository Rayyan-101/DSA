class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size(), ops = 0, flips = 0;
        vector<int> flipEnd(n, 0);
        
        for (int i = 0; i < n; i++) {
            flips -= flipEnd[i];
            
            if (((arr[i] + flips) & 1) == 0) {
                if (i + k > n) return -1;
                ops++,flips++;
                if (i + k < n) flipEnd[i + k]++;
            }
        }
        
        return ops;
    }
};
