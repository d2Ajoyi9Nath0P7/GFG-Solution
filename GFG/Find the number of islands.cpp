class Solution {
  public:
    // Function to find the number of islands.
    
    int dx[8] = {-1, -1, 0, +1, +1, +1, 0, -1};
    int dy[8] = {0, +1, +1, +1, 0, -1, -1, -1};
    
    
    bool isValid(int i,int j,int row,int col,vector<vector<char>>&grid)
    {
        if(i >= 0 && i < row && j >= 0 && j < col && grid[i][j] == '1')
        {
            return true;
        }
        return false;
    }
    
    void dfs(int r,int c,int row,int col,vector<vector<char>>&grid)
    {
        for(int i = 0 ; i < 8 ; i++)
        {
            if(isValid(r + dx[i],c  + dy[i],row,col,grid))
            {
                int nr = r  + dx[i];//0 + dx[i];
                int nc = c  + dy[i];//0 + dy[i];
            
                grid[nr][nc] = '0';
                dfs(nr,nc, row, col, grid);//
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid)
    {
        int row = grid.size(),col = grid[0].size(),cnt = 0;
        
        //vector<vector<int>>vis(row,vector<int>(col,0));
        /*for(int i = 0 ;  i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == '1'){
                    vis[i][j] = 1;
                }
            }
        }*/
        
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == '1')
                {
                    cnt++;
                    dfs(i,j,row,col,grid);
                }
            }
        }
        return cnt;
    }
};