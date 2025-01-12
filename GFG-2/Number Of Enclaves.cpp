class Solution {
  public:
  
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    
    bool isValid(int i,int j,vector<vector<int>>&grid)
    {
        if(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1)
        {
            return true;
        }
        return false;
    }
  
    void dfs(int i,int j,vector<vector<int>>&grid)
    {
        grid[i][j] = 0;
        
        for(int k = 0 ; k < 4 ; k++)
        {
            int new_i = i + dx[k];
            int new_j = j + dy[k];
            
            if(isValid(new_i,new_j,grid))
            {
                dfs(new_i,new_j,grid);
            }
        }
    }
  
    void solve(vector<vector<int>>&grid)
    {
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0; j < grid[0].size() ; j++)
            {
                if((i == 0 || j == 0 || i == grid.size()-1 || j == grid[0].size()-1) && grid[i][j] == 1)
                {
                    dfs(i,j,grid);
                }
            }
        }
    }
  
    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        int cnt = 0;
        solve(grid);
        
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[0].size() ; j++)
            {
                if(grid[i][j] == 1)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};