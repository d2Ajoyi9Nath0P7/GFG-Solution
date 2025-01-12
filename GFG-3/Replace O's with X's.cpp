// User function Template for C++

class Solution{
public:
    
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    
    bool isValid(int i,int j,int n,int m,vector<vector<int>>&vis,vector<vector<char>>&mat)
    {
        if(i >= 0 && i < n && j >= 0 && j < m && vis[i][j] == 0 && mat[i][j] == 'O')
        {
            return true;
        }
        return false;
    }
    
    bool boundary(int i,int j,int n,int m,vector<vector<char>>&mat)
    {
        if(i == 0 || i == n-1 || j == 0 || j == m-1){
            return true;
        }
        return false;
    }
    
    void dfs(int x,int y,int n,int m,vector<vector<int>>&vis,vector<vector<char>>&mat)
    {
        vis[x][y] = 1;
        for(int i = 0 ; i < 4 ; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            
            
            if(isValid(new_x,new_y,n,m,vis,mat))
            {
                dfs(new_x,new_y,n,m,vis,mat);
            }
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(boundary(i,j,n,m,mat) && mat[i][j] == 'O')
                {
                    dfs(i,j,n,m,vis,mat);
                }
            }
        }
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0; j < m ; j++)
            {
                if(vis[i][j] == 0)
                {
                    mat[i][j] = 'X';
                }
                else if(vis[i][j] == 1)
                {
                    mat[i][j] = 'O';
                }
            }
        }
        return mat;
    }
};