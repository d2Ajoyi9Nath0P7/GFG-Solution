/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    void solve(Node* root,vector<int>&vec)
    {
        if(root == NULL){
            return;
        }
        solve(root -> left,vec);
        vec.push_back(root -> data);
        solve(root -> right,vec);
    }
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int>vec;
        solve(root,vec);
        return vec;
    }
};