//User function Template for C++


class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)//5 0
    {
        int f = 1;
        f = f << k;
        
        int ans = f & n;
        
        if(ans == 0)
        {
            return false;
        }
        else{
            return true;
        }
    }
};