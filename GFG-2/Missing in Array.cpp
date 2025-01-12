// User function template for C++

class Solution{
  public:
    int missingNumber(vector<int>& array, int n)
    {
        int total = (n * (n+1)) / 2;
        int arr_sum = accumulate(array.begin(), array.end(), 0);
        return total - arr_sum;
    }
};