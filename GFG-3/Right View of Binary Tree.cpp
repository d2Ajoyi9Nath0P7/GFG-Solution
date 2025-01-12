/* A binary tree node has data, pointer to left child
   and a pointer to right child 
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

// Should return  right view of tree
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    
    
vector<int> solve(Node* root,vector<int>&vec)
{
        queue<Node*>q;
        vector<int>leftview;
        q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size();
            bool chk = false;
            vector<int>level;
            
            for(int i = 0 ; i < sz ; i++)
            {
                Node* frnt = q.front();
                q.pop();
                
                if(frnt->right != NULL)
                {
                    q.push(frnt->right);
                }
                if(frnt->left != NULL)
                {
                    q.push(frnt->left);
                }
                
                
                level.push_back(frnt->data);
                
                if(chk == false)
                {
                    chk = true;
                    
                    leftview.push_back(level[0]);
                }
            }
        }
        
        return leftview;
}

    vector<int> rightView(Node *root)
    {
       vector<int>vec;
       if(root == NULL)
       {
           return {vec};
       }
       return solve(root,vec);
    }
};
