/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    bool isleafNode(Node* root)
    {
        if(root->left == NULL && root -> right == NULL){
            return true;
        }
        return false;
    }
    
    void leftBoundary(Node* root,vector<int>&res)
    {
        Node* curr = root -> left;
        
        while(curr != NULL)
        {
            if(!isleafNode(curr))
            {
                res.push_back(curr->data);
            }
            if(curr -> left != NULL){
                curr = curr -> left;
            }
            else{
                curr = curr -> right;
            }
        }
    }
    
    void leafNode(Node* root,vector<int>&res)
    {
        if(isleafNode(root))
        {
            res.push_back(root->data);
            return;
        }
        if(root -> left != NULL)
        {
            leafNode(root->left,res);
        }
        if(root -> right != NULL){
            leafNode(root->right,res);
        }
    }
    
    void rightBoundary(Node* root,vector<int>&res)
    {
        vector<int>temp;
        Node* curr = root -> right;
        while(curr != NULL){
            if(!isleafNode(curr)){
                temp.push_back(curr->data);
            }
            if(curr -> right != NULL){
                curr = curr -> right;
            }
            else{
                curr = curr -> left;
            }
        }
        
        for(int i = temp.size() - 1 ; i >= 0 ; i--){
            res.push_back(temp[i]);
        }
    }

    vector <int> boundary(Node *root)
    {
        vector<int>res;
        if(root == NULL){
            return res;
        }
        if(!isleafNode(root)){
            res.push_back(root->data);
        }
        leftBoundary(root,res);
        leafNode(root,res);
        rightBoundary(root,res);
        
        return res;
    }
};