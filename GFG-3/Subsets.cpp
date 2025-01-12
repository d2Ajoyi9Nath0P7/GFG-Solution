// User function Template for C++

class Solution {
  public:
  
    void solve(int index,vector<int>&a,vector<int>&temp,vector<vector<int>>&res)
    {
        if(index == a.size())
        {
            res.push_back(temp);
            return;
        }
        
        solve(index+1,a,temp,res);
        temp.push_back(a[index]);
        solve(index+1,a,temp,res);
        temp.pop_back();
    }
  
    vector<vector<int>> subsets(vector<int>& a)
    {
        vector<vector<int>>res;
        vector<int>temp;
        solve(0,a,temp,res);
        sort(res.begin(),res.end());
        
        return res;
    }
};