/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/
#include<stack>
class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        Node* temp = head;
        stack<int>st;
        
        while(temp != NULL)
        {
            st.push(temp->data);
            temp = temp -> next;
        }
        
        temp = head;
        
        while(temp != NULL)
        {
            temp->data = st.top();
            temp = temp -> next;
            st.pop();
        }
        
        
        return head;
    }
};