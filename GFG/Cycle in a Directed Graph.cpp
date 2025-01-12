class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
bool dfs(int node,vector<int>&vis,vector<int>&path,vector<int>adj[])
{
    vis[node] = 1;
    path[node] = 1;
    for(auto child : adj[node])
    {
        if(!vis[child])
        {
            if(dfs(child,vis,path,adj) == true){
                return true;
            }
        }
        else{
            if(path[child] == 1){
                return true;
            }
        }
    }

    path[node] = 0;
    
    return false;
}
    
    bool isCyclic(int V, vector<int> adj[])
    {
    vector<int>vis(V,0);
    vector<int>path(V,0);

    for(int i = 0 ; i < V ; i++)
    {
        if(!vis[i])
        {
            if(dfs(i,vis,path,adj) == true)
            {
                return true;
            }
        }
    }
    
        return false;
        
    }
};