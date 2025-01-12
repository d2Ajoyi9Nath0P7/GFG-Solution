/* A binary tree Node

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
    public:
    
    void solve(Node* root,vector<int>&vec)
    {
        queue<Node*>q;
        q.push(root);
        vec.push_back(root->data);
        
        while(!q.empty())
        {
            Node* frnt = q.front();
            q.pop();
            
            if(frnt->left != NULL)
            {
                vec.push_back(frnt->left->data);
                q.push(frnt->left);
            }
            
            if(frnt->right != NULL)
            {
                vec.push_back(frnt->right->data);
                q.push(frnt->right);
            }
        }
    }
    
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
       vector<int>vec;
       
       solve(root,vec);
       
       return vec;
    }
};