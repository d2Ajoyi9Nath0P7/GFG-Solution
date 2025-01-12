class Solution 
{
    public:
    
    void dfs(int node,vector<int>adj[],vector<int>&vis)
    {
        vis[node] = 1;
        for(auto child : adj[node])
        {
            if(!vis[child])
            {
                dfs(child,adj,vis);
            }
        }
    }
    
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    int motherVertex = -1;
	    vector<int>vis(V,0);
	    int last_vertex;
	    for(int i = 0 ; i < V; i++)
	    {
	        if(!vis[i]){
	            last_vertex = i;
	            dfs(i,adj,vis);
	        }
	    }
	    
	    fill(vis.begin(),vis.end(),0);
	    dfs(last_vertex,adj,vis);
	    for(int i = 0 ; i < V ; i++)
	    {
	        if(vis[i] == 0)
	        {
	            return -1;
	        }
	    }
	    return last_vertex;
	}

};