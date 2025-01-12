// User function Template for C++

class Solution{
    
    int solve(int index,int target,int arr[],vector<vector<int>>&dp)
    {
        if(target == 0)
        {
            return 0;
        }
        if(index == 0)
        {
            if(arr[index] == target)
            {
                return 1;
            }
            return 0;
        }
        if(dp[index][target] != -1)
        {
            return dp[index][target];
        }
        
        int take = 0;
        if(target >= arr[index])
        {
            take = solve(index-1,target - arr[index],arr,dp);        
        }
    
        int not_take = solve(index - 1,target,arr,dp);
        
        return dp[index][target] = take | not_take;
    }
    
public:
    int equalPartition(int N, int arr[])
    {
        int sum = accumulate(arr,arr+N,0);
        if(sum % 2 != 0){
            return 0;
        }
        sum = sum >> 1;
        vector<vector<int>>dp(N,vector<int>(sum+1,-1));
        
        return solve(N-1,sum,arr,dp);
    }
};