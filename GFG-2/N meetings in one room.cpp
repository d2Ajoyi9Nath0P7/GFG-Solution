class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    #include<bits/stdc++.h>
    
    static bool cmp(pair<int,int>&a,pair<int,int>&b)
    {
        return a.second < b.second;
    }
    
    int maxMeetings(int n, int start[], int end[]) {
        int cnt = 1;
        vector<pair<int,int>>vp;
        for(int i = 0 ; i < n ; i++)
        {
            int x = start[i];
            int y = end[i];
            vp.push_back({x,y});
        }
        
        sort(vp.begin(),vp.end(),cmp);
        
        int maxVal = vp[0].second;
        
        for(int i = 1 ; i < vp.size() ; i++)
        {
            int x = vp[i].first;
            if(maxVal < x)
            {
                cnt++;
                maxVal = vp[i].second;
            }
        }
        return cnt;
    }
};