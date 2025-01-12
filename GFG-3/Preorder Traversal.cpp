

/* A binary tree node has data, pointer to left child
   and a pointer to right child  

/*
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

//Function to return a list containing the preorder traversal of the tree.
vector <int> preorder(Node* root)
{
    stack<Node*>st;
    vector<int>vec;
    if(root == NULL)
    {
        return vec;
    }
    
    st.push(root);
    
    while(!st.empty())
    {
        vec.push_back(st.top()->data);
        Node* frnt = st.top();
        st.pop();
        
        if(frnt->right != NULL)
        {
            st.push(frnt->right);
        }
        if(frnt->left != NULL)
        {
            st.push(frnt->left);
        }
    }
    
    return vec;
}