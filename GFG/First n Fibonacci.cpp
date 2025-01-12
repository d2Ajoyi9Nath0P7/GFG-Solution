//User function template for C++


class Solution
{
    long long solve(int index)
    {
        if(index == 1 || index == 2){
            return 1;
        }
        //if(dp[index] != -1){
        //    return dp[index];
        //}
        
        return solve(index-1) + solve(index-2);
    }
    
    public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        vector<long long>dp(n,-1);
    
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2 ;  i < n ; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp;
    }
};