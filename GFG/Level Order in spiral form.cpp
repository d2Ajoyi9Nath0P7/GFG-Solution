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


//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root){
        vector<int>res;
        
        if(root == NULL)
        {
            return res;
        }
        
        queue<Node*>q;
        q.push(root);
        int lvl = 0;

        while(!q.empty())   
        {
            vector<int>temp;
            int sz = q.size();
            lvl++;

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
                temp.push_back(frnt->data);
            }
            
            if(lvl % 2 == 1)
            {
                reverse(temp.begin(),temp.end());
                
                while(!temp.empty())
                {
                    res.push_back(temp.front());
                    temp.erase(temp.begin());
                }
            }
            else
            {
                while(!temp.empty())
                {
                    res.push_back(temp.front());
                    temp.erase(temp.begin());
                }
            }
        }
        
        return res;
    }