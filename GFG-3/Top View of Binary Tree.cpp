/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int>res;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        map<int,int>mp;
        
        while(!q.empty())
        {
            pair<Node*,int>front = q.front();
            Node* node = front.first;
            int index = front.second;
            q.pop();
            
            if(mp.find(index) == mp.end()){
                mp.insert({index,node->data});
            }
            if(node -> left != NULL){
                q.push({node->left,index-1});
            }
            if(node -> right != NULL){
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
