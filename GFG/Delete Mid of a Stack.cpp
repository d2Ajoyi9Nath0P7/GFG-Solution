// User function template for C++

class Solution {
  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s, int sizeOfStack) {
        int sz = (sizeOfStack + 1)/2;//2
        int deleteCnt = (sizeOfStack + 1) - sz;//(3+1)-2 = 2
        int stCnt = 0;
        int cnt = 0;
        
        
        stack<int>temp;

        
        while(!s.empty())
        {
            stCnt++;
            if(stCnt == deleteCnt)
            {
                s.pop();
                continue;
            }
            else
            {
                temp.push(s.top());
            }
            s.pop();
        }
        
        while(!temp.empty())
        {
            s.push(temp.top());
            temp.pop();
        }
        
        return;
    }
};