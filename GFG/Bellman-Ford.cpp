// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    
    
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        #define INF 100000000
        vector<int>dis(V,INF);
        dis[S] = 0;
        for(int i = 0 ; i < V-1 ; i++)
        {
            for(auto it : edges)
            {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                if(dis[u] != INF && dis[u] + wt < dis[v])
                {
                    dis[v] = dis[u] + wt;
                }
            }
        }
        
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if(dis[u] != INF && dis[u] + wt < dis[v])
            {
                return {-1};
            }
        }
        
        return dis;
    }
};
