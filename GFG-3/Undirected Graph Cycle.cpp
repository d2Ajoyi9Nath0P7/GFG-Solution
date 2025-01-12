class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int node,int par,vector<int>adj[],vector<int>&vis)
    {
        vis[node] = 1;
        for(auto child : adj[node])
        {
            if(!vis[child])
            {
                if(dfs(child,node,adj,vis)){
                    return true;
                }
            }
            else{
                if(par != child)
                {
                    return true;            
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        for(int i = 0 ; i < V ; i++)
        {
            if(!vis[i])
            {
                if(dfs(i,-1,adj,vis) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};