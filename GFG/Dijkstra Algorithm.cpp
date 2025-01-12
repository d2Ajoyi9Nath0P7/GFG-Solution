class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>distance(V);
        for(int i = 0 ; i < V ; i++)
        {
            distance[i] = 1e9;
        }
        distance[S] = 0;
        pq.push({0,S});
        while(!pq.empty())
        {
            int dis = pq.top().first;//0
            int node = pq.top().second;//0
            pq.pop();
            for(auto it : adj[node])
            {
                int nd = it[0];
                int wt = it[1];
                
                if(dis + wt < distance[nd])
                {
                    distance[nd] = dis + wt;
                    pq.push({distance[nd],nd});
                }
            }
        }
        return distance;
        
    }
};