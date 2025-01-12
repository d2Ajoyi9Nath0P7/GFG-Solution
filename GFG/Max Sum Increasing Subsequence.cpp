class Solution{
	public:
	
	int solve(int i,int pre,int arr[],int n,vector<vector<int>>&dp)
	{
	    if(i == n)
	    {
	        return 0;
	    }
	    
	    if(dp[i][pre+1] != -1)
	    {
	        return dp[i][pre+1];
	    }
	    
	    int not_take = 0 + solve(i+1,pre,arr,n,dp);
	    int take = 0;
	    
	    if(pre == -1 || arr[i]  > arr[pre])
	    {
	        take = arr[i] + solve(i+1,i,arr,n,dp);
	    }
	    
	    return dp[i][pre+1] = max(not_take,take);
	}
	
	int maxSumIS(int arr[], int n)  
	{
	    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
	    
	    for(int i = n-1 ; i >= 0 ; i--)
	    {
	        for(int pre = i-1 ; pre >= -1 ; pre--)
	        {
	            int notTake = 0 + dp[i+1][pre+1];
	            int take = 0;
	            
	            if(pre == -1 || arr[i] > arr[pre])
	            {
	                take = arr[i] + dp[i+1][i+1];
	            }
	            dp[i][pre+1] = max(take,notTake);
	        }
	    }
	    return dp[0][0];
	}
};