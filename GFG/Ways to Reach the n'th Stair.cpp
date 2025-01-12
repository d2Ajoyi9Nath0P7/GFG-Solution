class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
        int solve(int N,vector<int>&dp)
        {
            if(N == 0){
                return 1;
            }
            if(N < 0){
                return 0;
            }
        
        if(dp[N] != -1){
            return dp[N];
        }
        
        int first = solve(N-1,dp);
        int second = solve(N-2,dp);
        
        return dp[N] = (first + second) % 1000000007;
    }
    
    int countWays(int n)
    {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};
