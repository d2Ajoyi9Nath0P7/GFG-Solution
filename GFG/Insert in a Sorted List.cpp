/*
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data)
    {
        Node* pre = NULL;
        Node* curr = head;
        Node* Next = head;
        
        while(curr != NULL)
        {
            Next = Next -> next;
            
            if(curr -> data >= data)
            {
                if(pre == NULL)
                {
                    Node* newNode = new Node(data);
                    newNode -> next = curr;
                    return newNode;
                }
                Node* newNode = new Node(data);
                pre -> next = newNode;
                newNode -> next = curr;
                return head;
            }
            
            pre = curr;
            curr = Next;
        }
        
        Node* newNode = new Node(data);
        pre -> next = newNode;
        
        return head;
    }
};