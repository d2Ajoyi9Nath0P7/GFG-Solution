class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        
        map<int,int>mp_a;
        
        for(int i = 0 ; i < a.size() ; i++)
        {
            mp_a[a[i]]++;
        }
        
        bool chk = true;
        
        for(int i = 0 ; i < b.size() ; i++)
        {
            if(mp_a[b[i]] > 0)
            {
                mp_a[b[i]]--;
            }
            else
            {
                chk = false;
                break;
            }
        }
        
        if(chk == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};