class Solution {
  public:
    
    int solve(int index,int K,vector<int>&dp)
    {
        if(index < 0)
        {
            return 0;
        }
        if(index == 0)
        {
            return K;
        }
        
        if(dp[index] != -1)
        {
            return dp[index];
        }
        
        int take = solve(index-2,K,dp) + K;
        int not_take = solve(index-1,K,dp);
        
        
        
        return dp[index] = max(take,not_take);
    }
  
    int maximizeMoney(int N , int K) {
        
        if(N == 1 || N == 2)
        {
            return K;
        }
        
        vector<int>dp(N,-1);
        return solve(N-1,K,dp);
    }
};