/*
The structure of linked list is the following
struct Node
{
    string data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    bool compute(Node* head)
    {
        Node* temp = head;
        string str="";
        string str2;
        
        while(temp != NULL)
        {
            string val = temp->data;
            for(int i = 0 ; i < val.size() ; i++)
            {
                str += val[i];
            }
            temp = temp -> next;
        }
        str2 = str;
        
        reverse(str2.begin(),str2.end());
        
        return str == str2;
    }
};