// User function Template for C++
class Solution {
    
    void dfs(int node,vector<pair<int,int>>adj[],vector<int>&vis,stack<int>&st)
    {
        vis[node] = 1;
        for(auto child : adj[node])
        {
            int v = child.first;
            
            if(!vis[v])
            {
                dfs(v,adj,vis,st);
            }
        }
        st.push(node);
    }
    
    void toposort(int N,int M,vector<pair<int,int>>adj[],stack<int>&st)
    {
        vector<int>vis(N);
        for(int i = 0 ; i < N ;i++){
            if(!vis[i])
            {
                dfs(i,adj,vis,st);
            }
        }
    }
    
  public:
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges)
     {
        vector<pair<int,int>>adj[N];
        
        for(int i = 0 ; i < M ;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
        }
        
        stack<int>st;
        toposort(N,M,adj,st);
        vector<int>dis(N,2e5);
        
        dis[0] = 0;
        
        while(!st.empty())
        {
            int node = st.top();
            
            st.pop();
            
            for(auto child : adj[node])//
            {
                int nd = child.first;
                int wt = child.second;
                
                if(dis[node] + wt < dis[nd])
                {
                    dis[nd] = wt + dis[node];
                }
            }
        }
        
        for(int i = 0 ; i < N ; i++)
        {
            if(dis[i] == 2e5)
            {
                dis[i] = -1;
            }
        }
        
        return dis;
    }
};