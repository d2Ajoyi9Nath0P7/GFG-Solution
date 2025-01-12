//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	
	long long maxProduct(vector<int> arr, int n) {
	    long long max_v = arr[0];
	    for(int i = 0 ; i < n ; i++){
	        long long total = 1;
	        for(int j = i ; j < n; j++)
	        {
	            total = total * arr[j];
	            max_v = max(max_v,total);
	        }
	    }
	    return max_v;
	}
};