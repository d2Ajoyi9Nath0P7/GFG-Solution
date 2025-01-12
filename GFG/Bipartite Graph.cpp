class Solution {
public:
    
    bool dfs(int node,int V,vector<int>adj[],vector<int>&vis,vector<int>&col,int color)
    {
        vis[node] = 1;
        col[node] = color;
        
        for(auto child : adj[node])
        {
            if(vis[child] == 0)
            {
                if(!dfs(child,V,adj,vis,col,color^1)){//dfs()
                    return false;
                }
            }
            else{
                if(col[node] == col[child])
                {
                    return false;
                }
            }
        }
        return true;
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	   vector<int>vis(V,0);
	   vector<int>col(V,-1);
	   
	   for(int i = 0 ; i < V ; i++)
	   {
	       if(vis[i] == 0)
	       {
	            if(dfs(i,V,adj,vis,col,1) == false)
	            {
	               return false;
	            }
	       }
	   }
	   
	   return true;
	}
};