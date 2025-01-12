//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>Arr, int N, int k)
    {
        int left = 0,right = N-1;
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(Arr[mid] == k)
            {
                return mid;
            }
            else if(Arr[mid] > k)
            {
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};