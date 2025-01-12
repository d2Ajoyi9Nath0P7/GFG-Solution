// User function Template for C++

class Solution {
  public:
  
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    bool isValid(int i,int j,int row,int col,vector<vector<int>>&vis,vector<vector<int>>&grid)
    {
        if(i >= 0 && i < row && j >= 0 && j < col && vis[i][j] == 0 && grid[i][j] == 1)
        {
            return true;
        }
        return false;
    }
    
    int solve(vector<vector<int>>&grid,pair<int,int>&s,pair<int,int>&d)
    {
        if(s.first == d.first && s.second == d.second)
        {
            return 0;
        }
        int s_x = s.first;
        int s_y = s.second;
        int d_x = d.first;
        int d_y = d.second;
        
        /*if(s_x == s_y && d_x == d_y)
        {
            return 0;
        }*/
        
        
        int bound_row = grid.size();
        int bound_col = grid[0].size();
        
        vector<vector<int>>dis(bound_row,vector<int>(bound_col,0));
        vector<vector<int>>vis(bound_row,vector<int>(bound_col,0));    
    
        
        queue<pair<int,int>>q;
        q.push({s_x,s_y});
        vis[s_x][s_y] = 1;
        dis[s_x][s_y] = 0;
        
        while(!q.empty())
        {
            pair<int,int>frnt = q.front();
            int x = frnt.first;//0
            int y = frnt.second;//1
            q.pop();
            
            for(int i = 0 ; i < 4 ; i++)
            {
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                
                if(isValid(new_x,new_y,bound_row,bound_col,vis,grid))
                {
                    vis[new_x][new_y] = 1;
                    q.push({new_x,new_y});
                    dis[new_x][new_y] = dis[x][y] + 1;
                    if(new_x == d_x && new_y == d_y)
                    {
                        return dis[new_x][new_y];   
                    }
                }
            }
        }
        
        return -1;
    }
    
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,pair<int, int> destination)
    {

        if(grid[source.first][source.second] != 1)
        {
            return -1;
        }
        
        return solve(grid,source,destination);
    }
};