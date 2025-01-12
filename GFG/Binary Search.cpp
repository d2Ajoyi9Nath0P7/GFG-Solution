// User function template for C++

class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        int left = 0,right = n-1,mid;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(arr[mid] == k)
            {
                return mid;
            }
            else if(arr[mid] < k)
            {
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return -1;
    }
};