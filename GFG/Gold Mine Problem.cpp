class Solution{
public:

    int solve(int row,int col,vector<vector<int>>&M,int max_row,int max_col,vector<vector<int>>&dp)
    {
        if(row < 0 || col >= max_col || row >= max_row){
            return 0;
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        
    
        int upDia = M[row][col] + solve(row-1,col+1,M,max_row,max_col,dp);
        int right = M[row][col] + solve(row,col+1,M,max_row,max_col,dp);
        int downDia = M[row][col] + solve(row+1,col+1,M,max_row,max_col,dp);
        
        
        return dp[row][col] = max(downDia, max(upDia,right));
    }


    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int max_val = INT_MIN;
        for(int i = 0 ; i < n ; i++)
        {
             max_val = max(max_val,solve(i,0,M,n,m,dp));
        }
        return max_val;
    }
};