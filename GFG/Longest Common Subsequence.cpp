// function to find longest common subsequence

class Solution
{
    int solve(int i,int j,int n,int m,string s1,string s2,vector<vector<int>>&dp)
    {
        if(i < 0 || j < 0){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(s1[i] == s2[j]){
            return dp[i][j] = solve(i-1,j-1,n,m,s1,s2,dp) + 1;
        }
        
        else{
            return dp[i][j] =  max(solve(i,j-1,n,m,s1,s2,dp),solve(i-1,j,n,m,s1,s2,dp));
        }
    }
    
    public:
    //Function to find the length of longest common subsequence in two strings.
    
    int lcs(int n, int m, string s1, string s2)
    {
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= m ; j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);               
                }
            }
        }
        
        return dp[n][m];
    }
};