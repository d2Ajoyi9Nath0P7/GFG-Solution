// function Template for C++

/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void solve(Node* node)
    {
        if(node == NULL)
        {
            return;
        }
        solve(node->left);
        solve(node->right);
        
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
    void mirror(Node* node)
    {
        if(node == NULL)
        {
            return;
        }
        solve(node);
    }
};