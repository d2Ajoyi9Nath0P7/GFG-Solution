//User function Template for C++

class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        bitset<64>b1(n);
        int res = b1.count();
        if(res == 1){
            return true;
        }
        return false;
    }
};