    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n)
    {
        vector<int>vec;
        int max_v = -5;
        
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            if(a[i] >= max_v)
            {
                vec.push_back(a[i]);
            }
            max_v = max(max_v,a[i]);
        }
        reverse(vec.begin(), vec.end());
        return vec;
    }
};