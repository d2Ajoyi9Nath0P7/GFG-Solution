class Solution
{
	public:
	    
	    #define ll long long
	    ll solve(ll base,ll power,ll M)
	    {
	        ll res = 1;
	        while(power)
	        {
	            if(power & 1)
	            {
	                res = (res * base) % M;
	            }
	            base = (base * base) % M;
	            power >>= 1;
	        }
	        
	        return res;
	    }
	
		long long int PowMod(long long int x,long long int n,long long int M)
		{   
		    return solve(x,n,M);
		}
};