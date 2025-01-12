class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int>vis(V,0);
        vector<int>ans;
        queue<int>q;
        q.push(0);
        vis[0] = 1;
        
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for(int child : adj[front])
            {
                if(!vis[child])
                {
                    q.push(child);
                    vis[child] = 1;
                }
            }
        }
        return ans;
    }
};