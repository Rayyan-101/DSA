class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        priority_queue<int> pq;
        vector<int> result;
        for(int i = 0;i<k-1;i++)
        {
            pq.push(-arr[i]);
            result.push_back(-1);
        }
        
        for(int i = k-1;i<arr.size();i++)
        {
            pq.push(-arr[i]);
          
            if(pq.size()>k)
            {
                pq.pop();
            }
            result.push_back(-1*pq.top());
        }
        return result;
    }
};
