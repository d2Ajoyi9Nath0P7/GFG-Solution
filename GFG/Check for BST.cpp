class Solution
{
    public:
    
    //Function to check whether a Binary Tree is BST or not.
    int prev = INT_MIN;
    
    bool isBST(Node* root) 
    {
        if(root == NULL)
        {
            return true;
        }
        if(isBST(root->left) == false){
            return false;
        }
        if(root -> data <= prev){
            return false;
        }
        prev = root -> data;
        return isBST(root -> right);
    }
};