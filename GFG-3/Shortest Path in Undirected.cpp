// User funuction Template for C++
class Solution {
  public:
  
  void solve(vector<int>adj[],int node,queue<int>&q,vector<int>&vis,vector<int>&dis)
  {
        q.push(node);
        
        vis[node] = 1;
        dis[node] = 0;
        
        while(!q.empty())
        {
            int frnt = q.front();
            
            vis[frnt] = 1;
            q.pop();
            
            for(auto child : adj[frnt])
            {
                if(!vis[child])
                {
                    vis[child] = 1;
                    dis[child] = dis[frnt] + 1;
                    q.push(child);
                }
            }
        }
  }
  
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int>adj[N];
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(N,0);
        queue<int>q;
        vector<int>dis(N,-1);
        
        solve(adj,src,q,vis,dis);
        return dis;
    }
};