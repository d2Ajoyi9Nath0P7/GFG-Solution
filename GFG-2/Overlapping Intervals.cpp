class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        res.push_back(intervals[0]);
        for(int i = 1 ; i < intervals.size() ; i++)
        {
            vector<int>&recentInterval = res.back();
            
            if(intervals[i][0] <= recentInterval[1])
            {
                recentInterval[1] = max(intervals[i][1],recentInterval[1]);
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};