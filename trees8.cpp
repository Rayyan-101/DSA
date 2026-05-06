class Solution {
  public:
    int getSize(Node* root) {
        // code here
        if(root == NULL){
            return 0;
        }
        int leftSubTreeHeight = getSize(root->left);
        int rightSubTreeHeight = getSize(root->right);
        
        return 1 + leftSubTreeHeight + rightSubTreeHeight;
    }
};
