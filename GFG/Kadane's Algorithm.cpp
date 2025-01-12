class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int nums[], int n){
        long long current = 0, large = INT_MIN;
        
        for(int i = 0 ; i < n; i++)
        {
            current = current + nums[i];
            
            if(current < nums[i])
            {
                current = nums[i];
            }
            
            if(current > large)
            {
                large = current;
            }
        }
        
        return large;
    }
    
    
    
};