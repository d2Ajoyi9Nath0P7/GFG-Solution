class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        int left = 0,right = 0;
        long long curr_sum = arr[0];
        vector<int>index;
        
        if(s == 0)
        {
            auto it = find(arr.begin(),arr.end(),s);
            
            if(it != arr.end())
            {
                int indx = it - arr.begin();
                index.push_back(indx+1);
                index.push_back(indx+1);
                
                return index;
            }
            index.push_back(-1);
            return index;
        }
    
        while(right < n)
        {
            if(curr_sum == s)
            {
                index.push_back(left+1);
                index.push_back(right+1);
                
                return index;
            }
            else if(curr_sum < s)///bug
            {
                right++;
                if(right < n)
                {
                    curr_sum += arr[right]*1LL;
                }
            }
            else
            {
                curr_sum -= arr[left]*1LL;
                left++;
            }
        }
        
        index.push_back(-1);
        return index;
    }
};