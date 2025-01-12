// User function Template for C++

class Solution {
  public:
    
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    
    bool is_valid(int r,int c,int sr,int sc,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&vis)
    {
        if(r < n && c < m && r >= 0 && c >=0 && vis[r][c] == 0 && grid[r][c] == 1)
        {
            return true;
        }
        
        return false;
    }
    
    void dfs(int row,int col,vector<pair<int,int>>&vp,int row0,int col0,int m,int n,vector<vector<int>>&grid,vector<vector<int>>&vis)
    {
        vis[row][col] = 1;
        vp.push_back({row-row0,col-col0});
        
        for(int k = 0 ; k < 4 ; k++){
            
            int new_row = row + dx[k];
            int new_col = col + dy[k];
            
            if(is_valid(new_row,new_col,row,col,m,n,grid,vis))
            {
                dfs(new_row,new_col,vp,row0,col0,m,n,grid,vis); 
            }
        }   
    }
  
    int solve(int m, int n,vector<vector<int>>&grid,vector<vector<int>>&vis)
    {
        set<vector<pair<int,int>>>st;
        
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0; j < grid[0].size() ; j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int,int>>vp;
                    dfs(i,j,vp,i,j,m,n,grid,vis);
                    st.insert(vp);
                }
            }
        }
        
        return st.size();
    }
    
    int countDistinctIslands(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        return solve(m,n,grid,vis);
    }
};