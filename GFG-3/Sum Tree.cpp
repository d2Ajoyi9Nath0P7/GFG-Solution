/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
    int solve(Node* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        if(root->left == NULL && root ->right == NULL)
        {
            return root->data;
        }
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        if(left == -1 || right == -1)
        {
            return -1;
        }
        
        else if(root -> data == left + right)
        {
            return 2 * root -> data;
        }
        return -1;
    }
  
    bool isSumTree(Node* root)
    {
        if(root == NULL)
        {
            return true;
        }
        
        int res = solve(root);
        
        if(res == -1)
        {
            return false;
        }
        return true;
    }
};