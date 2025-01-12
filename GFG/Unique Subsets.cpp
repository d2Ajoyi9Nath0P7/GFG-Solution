class Solution
{
    void solve(int i,vector<int>&arr,int n,vector<int>&temp,set<vector<int>>&st)
    {
        if(i == arr.size())
        {
            st.insert(temp);
            return;
        }
        
        solve(i+1,arr,n,temp,st);
        
        temp.push_back(arr[i]);
        
        solve(i+1,arr,n,temp,st);
        temp.pop_back();
    }
    
    public:
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        vector<int>temp;
        set<vector<int>>st;
        
        sort(arr.begin(),arr.end());
        
        solve(0,arr,n,temp,st);
        
        vector<vector<int>>res(st.begin(),st.end());

        /*for(auto i : res)
        {
            for(auto j : i)
            {
                cout<<j<<" ";
            }
            cout<<"\n";
        }*/
        
        return res;
    }
};