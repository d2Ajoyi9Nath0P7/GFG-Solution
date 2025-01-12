/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

#include<bits/stdc++.h>

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        vector<int>vec1;
        vector<int>vec2;
        
        Node* temp = head;
        while(temp != NULL)
        {
            vec1.push_back(temp->data);
            temp = temp -> next;
        }
        vec2 = vec1;
        reverse(vec2.begin(),vec2.end());
        if(vec1 == vec2)
        {
            return true;
        }
        return false;
        
    }
};
