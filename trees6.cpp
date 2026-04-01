  public:
  
    void solve(Node* root,int key,Node* &small,Node* & greater){
      if(root == NULL){
          return;
      }
      
      if(root->left)solve(root->left,key,small,greater);
      
      if(root->data < key and (small == NULL or small->data < root->data)){
            small = root;
          }
          
      if(root->data > key and (greater == NULL or greater->data > root->data)){
              greater = root;
          }
          
      if(root->right)solve(root->right,key,small,greater);
      }
      
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* small = NULL;
        Node* greater = NULL;
        solve(root,key,small,greater);
        return {small,greater};
    }
};
