//User function template for C++

/*
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
    
    int solve(Node* node)
    {
        if(node == NULL)
        {
            return 0;
        }
        int lh = solve(node->left);
        int rh = solve(node->right);
        
        return 1 + max(lh,rh);
    }
    
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        return solve(node);
    }
};