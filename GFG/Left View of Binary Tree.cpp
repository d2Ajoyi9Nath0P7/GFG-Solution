

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

//Function to return a list containing elements of left view of the binary tree.

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
                
                if(frnt->left != NULL)
                {
                    q.push(frnt->left);
                }
                if(frnt->right != NULL)
                {
                    q.push(frnt->right);
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

    vector<int> leftView(Node *root)
    {
       vector<int>vec;
       if(root == NULL)
       {
           return {vec};
       }
       return solve(root,vec);
    }