class Solution 
{
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    
    bool isValid(int i,int j,int row,int col)
    {
        if(i >= 0 && i < row && j >= 0 && j < col)
        {
            return true;
        }
        return false;
    }
    
    int bfs(vector<vector<int>>&grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        
        int time = 0;
        queue<pair<int,int>>q;
        int frsh = 0;
        
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0; j < grid[0].size() ;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j] == 1)
                {
                    frsh++;
                }
            }
        }
        
        if(frsh == 0)
        {
            return 0;
        }
        
        while(!q.empty())
        {
            int sz = q.size();//
            
            while(sz != 0)
            {
                pair<int,int>frnt = q.front();
                int i = frnt.first;
                int j = frnt.second;
                q.pop();
                for(int k = 0 ; k < 4 ; k++)
                {
                    int new_x = i + dx[k];
                    int new_y = j + dy[k];
                    
                    if(isValid(new_x,new_y,row,col) && grid[new_x][new_y] == 1)
                    {
                        grid[new_x][new_y] = 2;
                        q.push({new_x,new_y});            
                    }
                }
                sz--;
            }
            time++;
        }
        
        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0; j < col ; j++)
            {
                if(grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return time-1;
    }
    
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid)
    {
        //vector<vector<int>>vis(row,vector<int>(col,0));
        //vector<vector<int>>dis(row,vector<int>(col));
        
        return bfs(grid);
    }
};