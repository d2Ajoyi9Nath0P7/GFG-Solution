
/*
Structure of the node of the linked list is as
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to check whether two linked lists are identical or not. 
bool areIdentical(struct Node *head1, struct Node *head2)
{
    while(head1 != NULL && head2 != NULL)
    {
        if(head1 -> data == head2 -> data)
        {
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        else
        {
            return false;
        }
    }
    
    if(head1 == NULL && head2 == NULL)
    {
        return true;
    }
    
    if(head1 == NULL || head2 == NULL)
    {
        return false;
    }
}