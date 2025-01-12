class Solution
{
    int solve(int arr[],int index,int target,vector<vector<int>>&dp)
    {
        if(index == 0)
        {
            if(arr[index] == 0 && target == 0){
                return 2;
            }
            else if(arr[index] == target){
                return 1;
            }
            else if(target == 0){
                return 1;
            }
            
            return 0;
        }
        
        if(dp[index][target] != -1)
        {
            return dp[index][target];
        }
        
        int not_take = solve(arr,index-1,target,dp);
        
        int take = 0;
        
        if(target >= arr[index])
        {
            take = solve(arr,index-1,target - arr[index],dp);
        }
        
        return dp[index][target] = (take + not_take) % 1000000007;
    }
    
	public:
	
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>>dp(n,vector<int>(sum + 1,-1));
        return solve(arr,n-1,sum,dp);
	}
};