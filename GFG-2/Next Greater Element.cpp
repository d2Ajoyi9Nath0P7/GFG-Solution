class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> vec, int n)
    {
        stack<long long>st;
        vector<long long>res;
        
        for(int i = n-1 ; i >= 0 ; i--)
        {
            while(!st.empty() && vec[i] >= st.top())
            {
                st.pop();
            }
            
            if(st.empty())
            {
                res.push_back(-1);
            }
            else
            {
                res.push_back(st.top());    
            }
            
            st.push(vec[i]);
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};