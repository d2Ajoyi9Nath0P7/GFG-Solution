class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&ans)
    {
        vis[node] = 1;
        for(auto child : adj[node])
        {
            if(!vis[child])
            {
                ans.push_back(child);
                dfs(child,adj,vis,ans);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int>vis(V,0);
        vector<int>ans;
        
        for(int i = 0 ; i < V; i++){
            if(!vis[i])
            {
                ans.push_back(i);
                dfs(i,adj,vis,ans);
            }
        }
        return ans;
    }
};