class Solution {
  public:
    int editDistance(string s, string t) {
        int n = s.size();
    int m = t.size();

    int dp[n+1][m+1];

    for(int i = 0 ; i <= n ; i++)
    {
        for(int j = 0 ; j <= m ; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[0][j] = j;
                dp[i][0] = i;
            }
            else
            {
                if(s[i-1] == t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
                }
            }
        }
    }
    
    
    return dp[n][m];
    }
};