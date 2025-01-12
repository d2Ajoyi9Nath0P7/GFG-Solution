class Solution
{
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    
    
    bool isValid(int i,int j,int N,vector<vector<int>>vis)
    {
        if(i >= 0 && i < N && j >= 0 && j < N && vis[i][j] == 0)
        {
            return true;
        }
        return false;
    }
    
    int solve(int i,int j,int des_x,int des_y,vector<vector<int>>&grid)
    {
        vector<vector<int>>vis(grid.size(),vector<int>(grid.size(),0));
        queue<pair<int,int>>q;
        
        q.push({i,j});
        
        while(!q.empty())
        {
            pair<int,int>frnt = q.front();
            int x = frnt.first;
            int y = frnt.second;
            if(x == des_x && y == des_y)
            {
                return 1;
            }
            q.pop();
            for(int i = 0 ; i < 4 ; i++)
            {
                int newX = dx[i] + x;
                int newY = dy[i] + y;
                
                if(isValid(newX,newY,grid.size(),vis) && grid[newX][newY] != 0)
                {
                    vis[newX][newY] = 1;
                    q.push({newX,newY});
                }
            }
        }
        
        return 0;
    }
    
    public:
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int src_x,src_y,dis_x,dis_y;
        for(int i = 0;  i < grid.size( ); i++)
        {
            for(int j = 0; j < grid.size() ; j++)
            {
                if(grid[i][j] == 1)
                {
                    src_x = i;
                    src_y = j;
                }
                else if(grid[i][j] == 2)
                {
                    dis_x = i;
                    dis_y = j;
                }
            }
        }
        
        return solve(src_x,src_y,dis_x,dis_y,grid);
    }
};