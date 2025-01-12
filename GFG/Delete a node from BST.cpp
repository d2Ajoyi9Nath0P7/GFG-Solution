
// Function to delete a node from BST.

Node* finalLastRight(Node* root)
{
    if(root -> right == NULL)
    {
        return root;
    }
    finalLastRight(root->right);
}

Node* helper(Node* root)//12
{
    if(root->left == NULL)
    {
        return root -> right;
    }
    else if(root -> right == NULL)
    {
        return root -> left;
    }
    
    Node* rightChild = root -> right; //13
    Node* lastright = finalLastRight(root->left); //11
    lastright -> right = rightChild;//
    
    return root -> left;
}

Node *deleteNode(Node *root, int X)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root -> data == X)
    {
        return helper(root);//helper(9)
    }
    
    Node* dummy = root;
    
    while(root != NULL)
    {
        if(root -> data > X)
        {
            if(root -> left  != NULL && root -> left -> data == X)
            {
                root -> left = helper(root -> left);
                break;
            }
            else
            {
                root = root->left;
            }
        }
        else
        {
            if(root -> right != NULL && root -> right -> data == X)
            {
                root -> right = helper(root -> right);//12
                break;
            }
            else
            {
                root = root->right;
            }
        }
    }
    
    return dummy;
}