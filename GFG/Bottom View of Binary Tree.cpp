//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector <int> bottomView(Node *root)
    {
        vector<int>res;
        if(root == NULL){
            return res;
        }
        queue<pair<Node*,int>>q;
        map<int,int>mp;
        q.push({root,0});
        
        while(!q.empty())
        {
            pair<Node*,int>frnt = q.front();
            Node* node = frnt.first;
            int index = frnt.second;
            q.pop();
            mp[index] = node -> data;
            //mp.insert({index,node->data});
            if(node->left != NULL)
            {
                q.push({node->left,index-1});
            }
            if(node->right != NULL)
            {
                q.push({node->right,index+1});
            }
        }
        
        for(auto it : mp)
        {
            res.push_back(it.second);
        }
        
        return res;
    }
};