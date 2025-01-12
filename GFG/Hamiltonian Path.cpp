class Solution
{
    #define pb push_back
    bool solve(int node,int N,vector<int>adj[],vector<int>vis,int cnt)
    {
        if(N == cnt)
        {
            return true;
        }
        
        vis[node] = 1;
        cnt++;
        for(auto child : adj[node])//
        {
            if(!vis[child])//vis[2]
            {
                if(solve(child,N,adj,vis,cnt))//sol(4)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    public:
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        vector<int>adj[N+1];
        for(auto i : Edges)
        {
            int u = i[0];
            int v = i[1];
            adj[u].pb(v);
            adj[v].pb(u);
        }
        
        vector<int>vis(N+1,0);
        int cnt = 1;
        
        for(int i = 1 ; i <= N ; i++)
        {
            if(solve(i,N,adj,vis,cnt))
            {
                return true;
            }
        }
        return false;
    }
};