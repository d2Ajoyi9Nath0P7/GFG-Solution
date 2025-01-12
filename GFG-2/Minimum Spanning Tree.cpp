class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        int sum = 0;
        vector<int>vis(V,0);
        
        while(!pq.empty())
        {
            pair<int,int>frnt = pq.top();
            int wt = frnt.first;
            int node = frnt.second;
            pq.pop();
            if(vis[node] == 1){
                continue;
            }
            vis[node] = 1;
            sum += wt;
            for(auto child : adj[node])
            {
                int nd = child[0];
                int wtt = child[1];
                if(!vis[nd]){
                    pq.push({wtt,nd});
                }
            }
        }
        
        return sum;
    }
};