//User function Template for C++

class Solution {
  public:
    void dfs(int node,vector<int>&vis,vector<int>ad[])
    {
        vis[node] = 1;
        
        for(auto child : ad[node])
        {
            if(vis[child] == 0)
            {
                dfs(child,vis,ad);
            }
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int V)
    {
        vector<int>ad[V];
        for(int i = 0 ; i < V ; i++)
        {
            for(int j = 0 ;j < V ; j++)
            {
                if(adj[i][j] == 1 && i != j)
                {
                    ad[i].push_back(j);
                    ad[j].push_back(i);
                }
            }
        }
        vector<int>vis(V,0);
        int cnt = 0;
        for(int i = 0 ; i < V ; i++)
        {
            if(vis[i] == 0)
            {
                cnt++;
                dfs(i,vis,ad);
            }
        }
        
        return cnt;
    }
};