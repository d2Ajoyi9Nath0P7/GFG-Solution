// User function Template for C++

class Solution{
public:
    
    #define ll long long
    #define mod 1000000007
    
    int solve(int n,int r,vector<vector<int>>&dp)
    {
        if(r == 0 || n == r)
        {
            return 1;
        }
        if(dp[n][r] != -1)
        {
            return dp[n][r];
        }
        
        return dp[n][r] = (solve(n-1, r, dp) + solve(n-1, r-1, dp)) % mod;
    }

    int nCr(int n, int r)
    {
        vector<vector<int>>dp(n+1,vector<int>(r+1,-1));
        if(r > n)
        {
            return 0;
        }
        return solve(n,r,dp);
    }
};