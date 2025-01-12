/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        //special case,if 1 hoi
        Node* temp = head;
        
        if(temp == NULL)
        {
            return;
        }
        
        Node* slow = temp;
        Node* fast = temp;
        Node* pre = slow;
    
        while(fast != NULL && fast -> next != NULL)
        {
            pre = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
            
            if(slow == fast)
            {
                break;
            }
        }
        
        if(slow != fast)
        {
            return;
        }
        
        slow = temp;
        
        if(slow == fast && pre -> next == head)
        {
            pre -> next = NULL;
            return;
        }
        
        while(slow -> next != fast -> next)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
        
        fast -> next = NULL;
        return;
    }
};