class Solution {
  public:
    long long solve(int* coins,int index,int target,vector<vector<long long>>&dp)
    {
    if(index == 0)
    {
        if(target % coins[index] ==0){
            return 1;
        }
        return 0;
    }
    if(target == 0)
    {
        return 1;
    }

    if(dp[index][target] != -1)
    {
        return dp[index][target];
    }

    long long not_take = solve(coins,index-1, target,dp);
    long long take = 0;

    if(target >= coins[index])
    {
        take = solve(coins,index,target - coins[index],dp);
    }

    return dp[index][target] = take + not_take;
}

    
    long long int count(int coins[], int N, int sum) {
        vector<vector<long long>>dp(N,vector<long long>(sum+1,-1));        
        return solve(coins,N-1,sum,dp);
    }
};