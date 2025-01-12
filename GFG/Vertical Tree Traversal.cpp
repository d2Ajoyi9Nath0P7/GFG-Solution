class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    
    void solve(Node* root,int ind,map<int,vector<int>>&mp)
    {
        queue<pair<int,Node*>>q;
        q.push({ind,root});
        
        while(!q.empty())
        {
            auto it = q.front();
            int index = it.first;
            Node* node = it.second;
            q.pop();
            
            mp[index].push_back(node->data);
            
            if(node->left != NULL)
            {
                q.push({index-1,node->left});
            }
            if(node->right != NULL)
            {
                q.push({index+1,node->right});
            }
        }
    }
    
    vector<int> verticalOrder(Node *root)
    {
        map<int,vector<int>>mp;//int,vector<int>
        solve(root,0,mp);
        vector<int>res;
        for(auto it : mp)//
        {
            for(auto i : it.second)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
