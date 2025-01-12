// Function to insert a node in a BST.



/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
    public:
        Node* insert(Node* node, int data)
        {
            Node* temp = node;
            Node* pre = node;
            
            while(temp != NULL)
            {
                if(temp -> data == data)
                {
                    return node;
                }
                else if(temp -> data > data)
                {
                    pre = temp;
                    temp = temp -> left;
                }
                else
                {
                    pre = temp;
                    temp = temp -> right;
                }
            }
            
            if(pre == NULL)
            {
                Node* newNode = new Node(data);
                //newNode -> data = data;
                pre = newNode;
                return pre;
            }
            
            if(pre -> data > data)
            {
                Node* newLeftNode = new Node(data);
                //newLeftNode -> data = data;
                pre -> left = newLeftNode;
            }
            else if(pre -> data < data)
            {
                Node* newRightNode = new Node(data);
                //newRightNode -> data = data;
                pre -> right = newRightNode;
            }
            
            return node;
    }
};