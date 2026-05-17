class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        stack<int> stack;
    
    // Iterate over the input vector
    for(int num : arr) {
        // If the stack is empty, push the integer onto the stack
        if(stack.empty()) {
            stack.push(num);
        } else {
            // If the integer has a different sign than the top of the stack, pop the top element
            if((stack.top() >= 0 && num < 0) || (stack.top() < 0 && num >= 0)) {
                stack.pop();
            } else {
                // Otherwise, push the integer onto the stack
                stack.push(num);
            }
        }
    }
    
    // Create a new vector to store the result
    vector<int> result;
    
    // Pop the elements from the stack and add them to the result vector
    while(!stack.empty()) {
        result.push_back(stack.top());
        stack.pop();
    }
    
    // Reverse the order of the elements in the result vector
    reverse(result.begin(), result.end());
    
    // Return the result vector
    return result;
    }
};
