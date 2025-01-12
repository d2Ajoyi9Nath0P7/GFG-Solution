/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution{
    public:
    
    int solve(Node* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        int lh = solve(root->left);
        if(lh == -1)
        {
            return -1;
        }
        int rh = solve(root->right);
        if(rh == -1)
        {
            return -1;
        }
        if(abs(lh-rh) > 1)
        {
            return -1;
        }
        
        return 1 + max(lh,rh);
    }
    
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if(solve(root) == -1){
            return false;
        }
        return true;
    }
};