class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        vector<int>res;
        res = a;
        for(int i = 0 ; i < b.size() ; i++)
        {
            res.push_back(b[i]);
        }
        sort(res.begin(),res.end());
        return res.at(k-1);
    }
};