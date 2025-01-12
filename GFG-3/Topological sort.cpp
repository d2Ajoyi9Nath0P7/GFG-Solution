class Solution
{
	public:
	
	vector<int>solve(int V,vector<int>adj[],queue<int>&q,vector<int>&res,int in[])
	{
	   for(int i = 0 ; i < V ; i++){
	       if(in[i] == 0){
	           q.push(i);
	       }
	   }
	   
	   while(!q.empty())
	   {
	       int frnt = q.front();
	       res.push_back(frnt);
	       q.pop();
	       for(auto child : adj[frnt])
	       {
	           in[child]--;
	           if(in[child] == 0){
	               q.push(child);
	           }
	       }
	   }
	   
	   return res;
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    queue<int>q;
	    vector<int>res;
	    int in[V] = {0};
	    for(int i = 0 ; i < V ;i++){
	        for(auto it : adj[i]){
	            in[it]++;
	        }
	    }
	    
	    solve(V,adj,q,res,in);
	    
	    return res;
	}
};