class Solution
{
    void solve(string S,int sz,list<char>&li,map<int,int>&mp,set<string>&st)
    {
        if(li.size() == sz)
        {
            string str;
            for(auto ch : li)
            {
                str += ch;
            }
            st.insert(str);
            
            return;
        }
        
        for(int i = 0 ; i < sz ; i++)
        {
            if(mp[i] == 0)
            {
                mp[i] = 1;
                li.push_back(S[i]);
                solve(S,sz,li,mp,st);
                li.pop_back();
                mp[i] = 0;
            }
        }
    }

    
	public:
		vector<string>find_permutation(string S)
		{
		   int sz = S.size();
		   list<char>li;
		   map<int,int>mp;
		   vector<string>ans;
		   set<string>st;
		   
		   solve(S,sz,li,mp,st);
		   
		   ans.assign(st.begin(),st.end());
		   return ans;
		}
};