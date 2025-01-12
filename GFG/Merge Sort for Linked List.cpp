/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        Node* temp = head;
        vector<int>vec;
        while(temp != NULL)
        {
            vec.push_back(temp->data);
            temp = temp -> next;
        }
        sort(vec.begin(),vec.end());
        Node* pre = new Node(vec[0]);
        head = pre;
        for(int i = 1 ; i < vec.size() ; i++)
        {
            Node* curr = new Node(vec[i]);
            pre -> next = curr;
            pre = curr;
        }
        pre -> next = NULL;
        return head;
    }
};