class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int solve(int index,int wt_left,int wt[],int price[],vector<vector<int>>&dp)//
    {
        if(index < 0 || wt_left <= 0)
        {
            return 0;
        }
        if(dp[index][wt_left] != -1){
            return dp[index][wt_left];
        }
        int ans = solve(index-1,wt_left,wt,price,dp);//
        
        if(wt_left - wt[index] >= 0)
        {
            ans = max(ans,price[index] + solve(index-1,wt_left - wt[index],wt,price,dp));//1 + kn(1, 4 - 3)
        }
        return dp[index][wt_left] = ans;
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
        return solve(n-1,W,wt,val,dp);
    }
};