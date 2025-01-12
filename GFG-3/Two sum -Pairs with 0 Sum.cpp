//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k)
    {
        unordered_map<int,int>mp;
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            int val = arr[i];
            int rem = k - val;
            
            if(mp.find(rem) != mp.end())
            {
                cnt += mp[rem];
            }
            mp[val]++;
        }
        return cnt;
    }
    

};