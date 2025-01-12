//User function Template for C++

class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        int cnt = 1;
        if(n == 0)
        {
            return 0;
        }
        
        while((n & 1) != 1)
        {
            n = n >> 1;
            cnt++;
        }
        return cnt;
    }
};