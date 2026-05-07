/*
Definition for Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool isSubTreeEqual(Node *root1, Node *root2) {
    // Base Case
    // Both NULL
    if(!root1 && !root2) {
        return true;
    }
    // Anyone one is null or data isnt matching
    if(!root1 || !root2 || root1->data != root2->data) {
        return false;
    }
    
    // Matching left & right
    return isSubTreeEqual(root1->left, root2->left) && isSubTreeEqual(root1->right, root2->right);
}

bool isSubTree(Node *root1, Node *root2) {
    // Base Case
    if(!root1) {
        return false;
    }
    // Matching data and subtree
    if(root1->data == root2->data && isSubTreeEqual(root1, root2)) {
        return true;
    }
    
    // Checking left & right
    return isSubTree(root1->left, root2) || isSubTree(root1->right, root2);
}
};
