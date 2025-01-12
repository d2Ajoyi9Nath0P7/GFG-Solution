// User function Template for C++

class Solution{
public:

    int solve(int index,int target,int val[],int wt[],vector<vector<int>>&dp)
    {
        if (index == 0 && target == 0)
        {
            return 0;
        }
        if(index < 0){
            return 0;
        }
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        
        int not_take = solve(index-1,target,val,wt,dp);
        int take = 0;
        
        if(target >= wt[index])
        {
            take = val[index] + solve(index,target - wt[index],val,wt,dp);
        }
        
        return dp[index][target] = max(take,not_take);
    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        
        return solve(N-1,W,val,wt,dp);
    }
};