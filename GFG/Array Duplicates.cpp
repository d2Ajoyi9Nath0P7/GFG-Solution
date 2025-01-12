class Solution{
  public:
    vector<int> duplicates(long long arr[], int n) {
        map<int,int>mp;
        for(int i = 0; i < n ; i++){
            mp[arr[i]]++;
        }
        vector<int>vec;
        bool chk = false;
        for(auto it : mp)
        {
            if(it.second > 1)
            {
                chk = true;
                vec.push_back(it.first);
            }
        }
        if(chk == false)
        {
            vec.push_back(-1);
            return vec;
        }
    }
};