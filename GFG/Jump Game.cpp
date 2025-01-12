//User function Template for C++

class Solution {
  public:
    int canReach(int A[], int N)
    {
        int boss = 0;
        for(int i = 0  ; i < N ;i++)
        {
            boss = max(boss, i+A[i]);
            
            if(boss >= N-1)
            {
                return true;
            }
            else if(i == boss && A[i] == 0)
            {
                return false;
            }
            else if(i + A[i] > boss)
            {
                boss = i + A[i];
            }
        }
        return false;
    }
};