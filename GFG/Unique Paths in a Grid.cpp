/User function Template for C++

class Solution {
  public:
 
    int solve(int i,int j,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(i <= n-1 && j <= m-1 && grid[i][j] == 0){
            return 0;
        }
        if(i == n-1 && j == m-1){
            return 1;
        }
        if(i == n || j == m)
        {
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int right = solve(i,j+1,n,m,grid,dp);    
        int down = solve(i+1,j,n,m,grid,dp);    
        
        return dp[i][j] = (right + down) % 1000000007;
    }
    
    
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,n,m,grid,dp);
    }
};