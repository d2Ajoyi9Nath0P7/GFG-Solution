class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        int low,high;
        if(arr.size() == 1)
        {
            return 1;
        }
        sort(arr.begin(),arr.end());
        low = arr[0];
        int maxV = 1;
        
        for(int i = 1 ; i < arr.size(); i++)
        {
            if(arr[i] - arr[i-1] <= 1)
            {
                high = arr[i];
                maxV = max(maxV,high-low+1);
            }
            else{
                low = arr[i];
            }
        }
        return maxV;
    }
};