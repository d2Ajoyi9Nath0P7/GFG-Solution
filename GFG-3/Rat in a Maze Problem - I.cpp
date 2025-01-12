// User function template for C++

class Solution{
    public:
    
    int dx[4] = {+1,0,0,-1};
    int dy[4] = {0,-1,+1,0};
    
    bool isValid(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&m,int n)
    {
        if(row < n && row >= 0 && col >= 0 && col < n && vis[row][col] == 0){
            return true;
        }
        return false;
    }
    
    void solve(vector<vector<int>>&m,int row,int col,int n,vector<vector<int>>&vis,string path,vector<string>&res)
    {
        if(row == n-1 && col == n-1)
        {
            res.push_back(path);
            
            return;
        }
        
        string p = "DLRU";
        
        for(int i = 0 ; i < 4 ; i++)
        {
            int new_r = dx[i] + row;
            int new_c = dy[i] + col;
            
            if(isValid(new_r,new_c,vis,m,n) && m[new_r][new_c] == 1)
            {
                vis[row][col] = 1;
                solve(m,new_r, new_c, n, vis, path+p[i], res);
                vis[row][col] = 0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<vector<int>>vis(n,vector<int>(n,0));
        vector<string>res;
        string path = "";
        
        if(m[0][0] == 1)
        {
            solve(m,0,0,n,vis,path,res);   
        }
        
        return res;
    }
};

    