class Solution {
  public:
  
    vector<int> LPS(string& pattern)
    {
        vector<int>lps(pattern.size(),0);
        int i = 0;
        
        for(int j = 1 ; j < pattern.size() ;)
        {
            if(pattern[i] == pattern[j])
            {
                i++;
                lps[j] = i;
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
                    i = 0;
                }
            }
        }
        return lps;
    }
    
    void KMP(string& text,string& pattern,vector<int>&lps,vector<int>&res)
    {
        int i = 0, j = 0;
        while(i < text.size())
        {
            if(text[i] == pattern[j])
            {
                i++;
                j++;
            }
            else
            {
                if(j != 0)
                {
                    j = lps[j-1];
                }
                else
                {
                    i++;
                }
            }
            if(j == pattern.size())
            {
                res.push_back((i-pattern.size())+1);
                //j = lps[j-1];
            }
        }
    }
  
    vector<int>solve(string& text,string& pattern)
    {
        vector<int>res;
        vector<int>lps = LPS(pattern); 
        KMP(text,pattern,lps,res);
        if(res.size() == 0)
        {
            return res;
        }
        else
        {
            return res;
        }
    }
  
    vector<int> search(string& pat, string& txt)
    {
        return solve(txt,pat);
    }
};