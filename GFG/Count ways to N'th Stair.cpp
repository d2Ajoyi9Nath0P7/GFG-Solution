

class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    long long countWays(int N)
    {
        int dp[N];
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2 ; i <= N ; i++){
            dp[i] = dp[i-2] + 1;
        }
        return dp[N];
    }
};