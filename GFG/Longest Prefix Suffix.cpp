
// User function template for C++

class Solution {
  public:
  
    vector<int> solve(string& str)
    {
        vector<int>lps(str.size(),0);
        
        int i = 0;
        
        for(int j = 1 ; j < str.size() ; )
        {
            if(str[i] == str[j])
            {
                lps[j] = i+1;
                i++;
                j++;
            }
            else
            {
                if(i != 0)
                {
                    i = lps[i-1];
                }
                else
                {
                    lps[j] = 0;
                    j++;
                }
            }
        }
        return lps;
    }
  
    int lps(string str) {
        vector<int>lps = solve(str);
        return lps[str.size()-1];
    }
};