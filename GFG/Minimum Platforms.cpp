class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr,arr + n);
        sort(dep,dep + n);
        
        int platform_req = 1;
        int i = 1;
        int max_v = platform_req;
        int j = 0;
    
        
        while(i < n && j < n)
        {
            if(arr[i] <= dep[j])
            {
                platform_req++;
                max_v = max(max_v,platform_req);
                i++;
            }
            else
            {
                platform_req--;
                j++;
            }
        }
        
        return max_v;
    }
};