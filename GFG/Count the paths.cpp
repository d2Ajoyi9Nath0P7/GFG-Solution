class Solution {
public:
    
    void dfs(vector<int>adj[],int s,int d,vector<vector<int>>&vec,vector<int>&path)
    {
        path.push_back(s);//0 4
        if(s == d)
        {
            vec.push_back(path);//0 4
        }
        else
        {
            for(auto child : adj[s])
            {
                dfs(adj,child,d,vec,path);//dfs(4) dfs(3)
            }
        }
        path.pop_back();
    }
    
	int possible_paths(vector<vector<int>>edges, int n, int s, int d)
	{
	    vector<int>adj[n];
	    vector<int>vis(n,0);
	    vector<vector<int>>vec;
        vector<int>path;
        
	    for(auto edge : edges)
	    {
	        adj[edge[0]].push_back(edge[1]);
	    }
	    dfs(adj,s,d,vec,path);
	    
	    
	    return vec.size();
	}
};