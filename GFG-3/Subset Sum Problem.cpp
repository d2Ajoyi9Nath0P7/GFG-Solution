//User function template for C++

class Solution{
public:

    bool isSubsetSum(vector<int>arr, int sum)
    {
        int n = arr.size();
        
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
        
        for(int index = 0 ; index <= arr.size() ; index++)
        {
            dp[index][0] = true;
        }
        
        for(int index = 1 ; index <= n; index++)
        {
            for(int target = 1 ; target <= sum ; target++)
            {
                bool not_take = dp[index-1][target];
                bool take = false;
                
                if(target >= arr[index-1])
                {
                    take = dp[index-1][target-arr[index-1]];//[1-1][6-2]=[0][4]
                }
                dp[index][target] = take | not_take;
            }
        }
        return dp[n][sum];
    }
};