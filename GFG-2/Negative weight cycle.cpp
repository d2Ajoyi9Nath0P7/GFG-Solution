class Solution {
public:

    const int INF = 1e9+1000000000;
    
    int bellmenford(int node,vector<pair<int,int>>adj[],vector<int>&distance)
    {
        for(int itaration = 1 ; itaration <= node-1 ; itaration++)
        {
            for(int u = 0 ; u < node ; u++)
            {
                for(pair<int,int> i : adj[u])
                {
                    int v = i.first;
                    int wt = i.second;
                    
                    if(distance[u] != INF && distance[u] + wt < distance[v])
                    {
                        distance[v] = distance[u] + wt;
                    }
                }
            }
        }
        
        
        for(int u = 0 ; u < node ; u++)
        {
            for(auto it : adj[u])
            {
                int v = it.first;
                int wt = it.second;
                
                if(distance[u] + wt < distance[v])
                {
                    return 1;
                }
            }
        }
        return 0;
    }

	int isNegativeWeightCycle(int n, vector<vector<int>>edges)
	{
	    vector<pair<int,int>>adj[n];
	    vector<int>distance(n,INF);
	    distance[0] = 0;
	    
	    for(auto i : edges)
	    {
	        int u = i[0];
	        int v = i[1];
	        int wt = i[2];
	        adj[u].push_back({v,wt});
	    }
	    return bellmenford(n,adj,distance);
	}
};