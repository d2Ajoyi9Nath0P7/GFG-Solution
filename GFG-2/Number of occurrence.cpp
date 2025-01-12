//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    map<int,int>mp;
	    for(int i = 0 ; i < n ; i++)
	    {
	        if(arr[i] == x)
	        {
	            mp[arr[i]]++;    
	        }
	    }
	    
	    if(mp.find(x) != mp.end())
	    {
	        return mp[x];
	    }
	    return 0;
	}
};