class Solution 
{
    public:
    
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    
    bool isValid(int i,int j,int row,int col,vector<vector<int>>&grid)
    {
        if(i >= 0 && i < row && j >= 0 && j < col)
        {
            return true;
        }
        return false;
    }

    void solve(vector<vector<int>>&grid,vector<vector<int>>&res,vector<vector<int>>&vis,queue<pair<pair<int,int>,int>>&q,int row,int col)
    {
        while(!q.empty())
        {
            pair<pair<int,int>,int>frnt = q.front();
            
            int i = frnt.first.first;
            int j = frnt.first.second;
            int distance = frnt.second;
            
            
            q.pop();
            
            res[i][j] = distance;
            
            for(int k = 0 ; k < 4 ; k++)
            {
                int new_i = i + dx[k];
                int new_j = j + dy[k];
                
                if(isValid(new_i,new_j,row,col,grid) && vis[new_i][new_j] == 0)
                {
                    q.push({{new_i,new_j},distance + 1});
                    vis[new_i][new_j] = 1;
                }
            }
        }
    }
    
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int row = grid.size();
	    int col = grid[0].size();
	    
	    vector<vector<int>>res(row,vector<int>(col));
	    vector<vector<int>>vis(row,vector<int>(col,0));
	    
	    queue<pair<pair<int,int>,int>>q;
	    
	    for(int i = 0 ; i < row ; i++)
	    {
	        for(int j = 0; j < col ; j++)
	        {
	            if(grid[i][j] == 1)
	            {
	                vis[i][j] = 1;
	                q.push({{i,j},0});
	            }
	        }
	    }
	    
	 
	    pair<pair<int,int>,int>frnt = q.front();
	    
	    
	    solve(grid,res,vis,q,row,col);
	    return res;
	}
};