class Solution {
  public:
  
  void solve(vector<pair<int,int>>adj[],int s,int e,vector<int>&dis,vector<int>&parent)
  {
        parent[s] = s;
        priority_queue <pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,s});
        
        dis[s] = 0;
        
        while(!pq.empty())
        {
            pair<int,int>frnt = pq.top();
            
            int distance = frnt.first;
            int node = frnt.second;
            
            pq.pop();
            
            for(auto it : adj[node])
            {
                int nd = it.first;
                int wt = it.second;
                
                if(distance + wt < dis[nd])
                {
                    parent[nd] = node; 
                    dis[nd] = distance + wt;
                    pq.push({dis[nd],nd});
                }
            }
        }
   }
  
  
  
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges)
    {
        vector<pair<int,int>>adj[n+1];
        vector<int> dis(n+1, 1e9);
        vector<int> parent(n+1, -1);

        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        solve(adj, 1, n, dis, parent);

        if(dis[n] == 1e9)
        {
            return {-1};
        }
        
        /*for(int i = 1 ; i <= n ; i++)
        {
            cout<<dis[i]<<" ";
        }
        cout<<"\n";*/

        vector<int>res;
        
        int ans = n;
        
        
        while(ans != 1)
        {
            res.push_back(ans);
            ans = parent[ans];
        }
        res.push_back(1);
        res.push_back(dis[n]);
        reverse(res.begin(), res.end());
        
        
        return res;
    }
};