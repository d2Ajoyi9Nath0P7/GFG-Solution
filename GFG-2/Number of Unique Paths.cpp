//User function template in C++

class Solution
{
    int solve(int i,int j,int row,int col,vector<vector<int>>&dp)
    {
        if(i == row && j == col)
        {
            return 1;
        }
        if(i > row || j > col)
        {
            return 0;
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        int right = solve(i,j+1,row,col,dp);
        int down = solve(i+1,j,row,col,dp);
        
        return dp[i][j] = down + right;
    }
    
    public:
    //Function to find total number of unique paths.
    
    int NumberOfPath(int a, int b)
    {
        int dp[a+1][b+1];
        
        for(int i = 0 ; i <= a ; i++)
        {
            for(int j = 0 ; j <= b ; j++)
            {
                dp[i][j] = 0;
            }
        }
        
        for(int i = 1 ; i <= b ; i++)
        {
            dp[1][i] = 1;//dp[1][1],[1][2],[1][3]
        }
        for(int i = 1 ; i <= a ; i++)
        {
            dp[i][1] = 1; 
        }
        
        for(int i = 2 ; i <= a ; i++)
        {
            for(int j = 2 ; j <= b ; j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[a][b];
    }
};
