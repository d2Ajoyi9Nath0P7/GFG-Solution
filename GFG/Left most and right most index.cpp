class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        pair<long,long>p;
        int left = 0,right = v.size()-1,ind = -1;
        
        while(left <= right)
        {
            int mid = (left + right)/2;
            if(v[mid] == x)
            {
                ind = mid;
                right = mid - 1;
            }
            else if(v[mid] > x)
            {
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        p.first = ind;
        
        left = 0,right = v.size()-1;
        ind = -1;
        
        while(left <= right)
        {
            int mid = (left + right)/2;
            if(v[mid] == x)
            {
                ind = mid;
                left = mid + 1;
            }
            else if(v[mid] > x)
            {
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        p.second = ind;
        return p;
    }
};