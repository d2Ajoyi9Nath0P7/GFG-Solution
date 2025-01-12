// User function Template for C++

/*class Node {
public:
    int data;
    Node* next;
  
    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }
  
    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};*/

class Solution {
  public:
    Node* constructLL(vector<int>& arr)
    {
        Node* pre = new Node(arr[0]);
        Node* head = pre;
        for(int i = 1 ; i < arr.size() ;i++)
        {
            Node* curr = new Node(arr[i]);
            pre -> next = curr;
            pre = curr;
        }
        pre -> next = NULL;
        return head;
    }
};