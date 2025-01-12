//User function Template for C++

/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
    public:
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {
        Node* temp = head;
        Node* fast = head;
        Node* slow = head;
        Node* cyclefound = head;
        while(fast != NULL && fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            
            if(fast == slow)
            {
                cyclefound = slow;
                break;
            }
        }
        
        if(fast != slow)
        {
            return -1;
        }
        
        slow = head;
        while(slow != cyclefound)
        {
            slow = slow -> next;
            cyclefound = cyclefound -> next;
        }
        
        return slow->data;
    }
};