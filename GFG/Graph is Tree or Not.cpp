class Solution {
  public:
  
    bool dfs(int node,int parent,vector<int>Adj[],vector<int>&vis)
    {
        vis[node] = 1;
        for(auto child : Adj[node])
        {
            if(!vis[child])
            {
                if(dfs(child,node,Adj,vis))
                {
                    return true;
                }
            }
            else
            {
                if(child != parent)
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    
    void dffs(int node,vector<int>adj[],vector<int>&vis)
    {
        vis[node] = 1;
        for(auto child : adj[node])
        {
            if(!vis[child])
            {
                dffs(child,adj,vis);
            }
        }
    }
    
  
    int isTree(int n, int m, vector<vector<int>> &adj)
    {
        vector<int>A[n];
        for(auto i : adj)
        {
            int u = i[0];
            int v = i[1];
            A[u].push_back(v);
            A[v].push_back(u);
        }
        vector<int>vis(n,0);
        vector<int>viis(n,0);
        
        int cnt = 0;
        
        for(int i = 0; i < n ; i++)
        {
            if(!viis[i])
            {
                cnt++;
                dffs(i,A,viis);
            }
        }
        
        for(int i = 0 ; i < n ; i++)
        {
            if(!vis[i])
            {
                if(dfs(i,-1,A,vis)){
                    return 0;
                }
            }
        }
        //cycle not detected and cc = 1
        if(cnt == 1)
        {
            return 1;
        }
        return 0;//cycle not detected and cc = 0
    }
};