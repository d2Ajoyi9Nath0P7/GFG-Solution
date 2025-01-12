class Solution {
  public:
  
    #define mod 1000000007
    
    int solve(int n,vector<int>&dp)
    {
        if(n <= 2)
        {
            return n;
        }
        
        if(dp[n] != -1)
        {
            return dp[n];
        }
        return dp[n] = (solve(n-1,dp) + solve(n-2,dp)) % mod;
    }
  
    int numberOfWays(int n) {
        vector<int>dp(n+1,-1);
        /*dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2 ; i <= n ; i++)
        {
            dp[i] = (dp[i-1] + dp[i-2]) % mod;
        }*/
        
        return solve(n,dp);
    }
};