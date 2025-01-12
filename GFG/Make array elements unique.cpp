// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        sort(arr.begin(),arr.end());
        long long int cnt = 0;
        
        for(int i = 1 ; i < arr.size() ; i++)
        {
            int firstPointer = i;
            int secondPointer = i-1;
            
            if(arr[firstPointer] == arr[secondPointer])
            {
                arr[i] = arr[firstPointer] + 1;
                cnt++;
            }
            else if(arr[secondPointer] > arr[firstPointer])
            {
                int preV = arr[firstPointer];
                arr[i] = arr[firstPointer] + ((arr[secondPointer] - arr[firstPointer])+1);
                cnt = cnt + (arr[i] - preV);
            }
        }
        return cnt;
    }
};