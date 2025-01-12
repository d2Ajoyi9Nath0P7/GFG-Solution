//User function Template for C++
class Solution
{
public:
    
    int solve(int x,int y,vector<vector<int>>&dp)
    {
        if(x == 0 && y == 0){
            return 1;
        }
        if(x < 0 || y < 0){
            return 0;
        }
        if(dp[x][y] != -1){
            return dp[x][y];
        }
        
        int left = solve(x,y-1,dp);
        int up = solve(x-1,y,dp);
        
        return dp[x][y] = (left + up) % 1000000007;
    }

    int ways(int x, int y)
    {
        vector<vector<int>>dp(x+1,vector<int>(y+1,-1));
        return solve(x,y,dp);
    }
};