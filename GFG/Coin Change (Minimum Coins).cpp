class Solution{
    
    int min_coin(int i,int target,vector<int>&vec,vector<vector<int>>&dp)//(1,-1)
    {
        //cout<<i<<" "<<target<<"\n";
    if(i == 0)
    {
        if(target % vec[i] == 0)
        {
            return target / vec[i];
        }
        return 1e9;
    }
    
    if(dp[i][target] != -1)
    {
        return dp[i][target];
    }

    int not_take = 0 + min_coin(i-1,target,vec,dp);
    int take = INT_MAX;

    if(target >= vec[i])
    {
        take = 1 + min_coin(i,target - vec[i],vec,dp);//1 + f(1,1)
    }

    return dp[i][target] = min(take,not_take);
}
	public:
	int minCoins(vector<int> &coins, int M, int V) 
	{
	    vector<vector<int>>dp(M,vector<int>(V+1,-1));//
	    
        int x = min_coin(M-1,V,coins,dp);
        
        if(x == 1e9){
            return -1;
        }
        return x;
	}
};