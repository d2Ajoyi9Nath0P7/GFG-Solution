
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
    Node* curr = head;
    Node* temp = curr;
    
    if(curr == NULL)
    {
        return NULL;
    }
    else if(curr -> next == NULL)
    {
        return curr;
    }
    
    while(curr -> next != NULL)
    {
        if(curr -> data == curr -> next -> data)
        {
            curr -> next = curr -> next -> next;
        }
        else
        {
            curr = curr -> next;
        }
    }
    return temp;
}