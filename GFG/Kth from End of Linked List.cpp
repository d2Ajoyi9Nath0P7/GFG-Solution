/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

// Function to find the data of kth node from the end of a linked list.
class Solution {
  public:
    int getKthFromLast(Node *head, int k) {
        
        int n = 0;
        Node* temp = head;
        Node* temp2 = head;
        
        while(temp != NULL)
        {
            n++;
            temp = temp -> next;
        }
        
        if(n < k){
            return -1;
        }
        
        if(head == NULL)
        {
            return -1;
        }
        int cnt = 0;
        while(n - k  > cnt)
        {
            cnt++;
            temp2 = temp2 -> next;
        }
        return temp2 -> data;
    }
};