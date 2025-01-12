/*

Definition for Binary Tree Node
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

class Solution {
  public:
  
  void solve(Node* root,vector<vector<int>>&res,vector<int>&temp)
  {
      if(root == NULL)
      {
          return;
      }
      temp.push_back(root->data);
      solve(root->left,res,temp);
      solve(root->right,res,temp);
      
      if(root -> left == NULL && root -> right == NULL)
      {
          res.push_back(temp);
      }
      temp.pop_back();
  }
  
    vector<vector<int>> Paths(Node* root)
    {
        vector<vector<int>>res;
        vector<int>temp;
        solve(root,res,temp);
        
        return res;
    }
};