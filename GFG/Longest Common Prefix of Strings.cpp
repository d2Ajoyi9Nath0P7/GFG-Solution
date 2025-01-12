// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        
        sort(arr.begin(),arr.end());
        
        int n = arr[0].size();
        int m = arr[arr.size()-1].size();
        
        int sz = min(n,m);
        
        string str1 = arr[0];
        string str2 = arr[arr.size()-1],res = "";
        
        for(int i = 0 ; i < sz ; i++)
        {
            if(str1[i] == str2[i])
            {
                res += str1[i];
            }
            else{
                break;
            }
        }
        
        if(res.size() == 0)
        {
            return "-1";
        }
        return res;
    }
};