
//User function Template for C++

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */

//Function to return a list containing the postorder traversal of the tree.
void solve(Node* root,vector<int>&vec)
{
    if(root == NULL)
    {
        return;
    }
    solve(root->left,vec);
    solve(root->right,vec);
    vec.push_back(root->data);
}
vector <int> postOrder(Node* root)
{
    vector<int>vec;
    
    solve(root,vec);
    return vec;
}