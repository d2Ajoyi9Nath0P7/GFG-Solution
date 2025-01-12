class Solution {
    
    #define mod 1000000007
	public:
	
	int cnt = 0;
    void solve(string& s,int index,vector<int>&dp)//(s,6)
    {
        if(index == s.size())
        {
            cnt++;
            return;
        }
        if(s[index] == '0')
        {
            return;
        }
        if(dp[index] != -1)
        {
            cnt = (cnt + dp[index]) % mod;
            return;
        }
        
        solve(s,index+1,dp);

        if (index < s.size() - 1)
        {
            int a = s[index]-'0';
            int b = s[index+1]-'0';
            int val = (a * 10) + b;
            if(val <= 26)
            {
                solve(s,index+2,dp);
            }
        }
        dp[index] = cnt % mod;
     }
	
	    int CountWays(string str)
		{
		    int sz = str.size();
            vector<int>dp(sz+1,-1);
            solve(str,0,dp);//11026
            
            return cnt;
		}
};