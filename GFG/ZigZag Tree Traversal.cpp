//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
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
            
            if(lvl % 2 == 0)
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
};