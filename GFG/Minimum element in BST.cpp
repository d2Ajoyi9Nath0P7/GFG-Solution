// User function Template for C++

// Function to find the minimum element in the given BST.

/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
*/

class Solution {
  public:
    
    int min_v = INT_MAX;
    
    void solve(Node* root)
    {
        if(root == NULL)
        {
            return;
        }
        min_v = min(min_v,root->data);
        solve(root->left);
        solve(root->right);
    }
  
    int minValue(Node* root)
    {
        if(root == NULL)
        {
            return -1;
        }
        solve(root);
        return min_v;
    }
};