// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        unordered_map<string,vector<string>>mp;
        
        for(auto i : arr)
        {
            string str = i;
            sort(str.begin(),str.end());
            mp[str].push_back(i);
        }
        vector<vector<string>>res;
        
        for(auto i : mp)
        {
            res.push_back(i.second);
        }
        return res;
    }
};