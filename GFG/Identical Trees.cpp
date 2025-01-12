/* A binary tree node


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


   
class Solution
{
    bool solve(Node* r1,Node* r2)
    {
        if(r1 == NULL && r2 == NULL)
        {
            return true;
        }
        if(r1 -> data != r2 -> data)
        {
            return false;
        }
        if((r1 != NULL && r2 == NULL) ||(r1 == NULL && r2 != NULL))
        {
            return false;
        }
        return solve(r1->left,r2->left) && solve(r1->right,r2->right);
    }
    
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        if(r1 == NULL && r2 == NULL)
        {
            return true;
        }
        return solve(r1,r2);
    }
};