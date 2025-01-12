// User function Template for C++

class Solution{
public:
    
    /*int solve(int row,int col,int N,vector<vector<int>>&Matrix,vector<vector<int>>&dp)
    {
        if(row == 0)
        {
            return Matrix[row][col];
        }
        
        if(dp[row][col] != -1)
        {
            return dp[row][col];
        }
        int x,y,z;
        
            x = solve(row-1,col,N,Matrix,dp) + Matrix[row][col];
            
            if(col < N - 1)
            {
                 y = solve(row-1,col+1,N,Matrix,dp) + Matrix[row][col];    
            }
            else
            {
                y = INT_MIN;
            }
            if(col > 0)
            {
                 z = solve(row-1,col-1,N,Matrix,dp) + Matrix[row][col];   
            }
            else
            {
                z = INT_MIN;
            }
            return dp[row][col] = max(x,max(y,z));
    }*/

    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int dp[N][N];
        
        vector<int>pre(N,0),curr(N,0);
        
        for(int i = 0 ; i < N ; i++)
        {
            pre[i] = Matrix[0][i];
        }
        
        for(int i = 1 ; i < N ; i++)
        {
            for(int j = 0 ; j < N ; j++)
            {
                int x = pre[j] + Matrix[i][j];
                
                int y = Matrix[i][j];
                
                if(j-1 >= 0)
                {
                     y += pre[j-1];    
                }
                else
                {
                    y = INT_MIN;
                }
                
                int z = Matrix[i][j];
                
                if(j+1 < N)
                {
                     z += pre[j+1];   
                }
                else
                {
                    z = INT_MIN;
                }
                
                curr[j] = max(x,max(y,z));
            }
            
            pre = curr;
        }
        
        int max_v = INT_MIN;
        
        for(int i = 0 ; i < N ; i++)
        {
            max_v = max(max_v,pre[i]);
        }
        
        return max_v;
    }
};