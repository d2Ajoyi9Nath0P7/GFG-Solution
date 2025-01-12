// User function Template for C++

class Solution {
    
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    
    bool isValid(int i,int j,int N,int M,vector<vector<int>>&vis,vector<vector<int>>&A)
    {
        if(i >= 0 && i < N && j >= 0 && j < M && vis[i][j] == 0 && A[i][j] == 1)
        {
            return true;
        }
        return false;
    }
    
    int bfs(int N,int M,vector<vector<int>>&A,int X,int Y)
    {
        vector<vector<int>>dis(N,vector<int>(M));
        vector<vector<int>>vis(N,vector<int>(M,0));
        vis[0][0] = 1;
        dis[0][0] = 0;
        queue<pair<int,int>>q;
        q.push({0,0});
        
        while(!q.empty())
        {
            pair<int,int>frnt = q.front();
            int i = frnt.first;
            int j = frnt.second;
            q.pop();
            for(int k = 0 ; k < 4 ; k++)
            {
                int new_x = i + dx[k];
                int new_y = j + dy[k];
                
                if(isValid(new_x,new_y,N,M,vis,A))
                {
                    dis[new_x][new_y] = dis[i][j] + 1;
                    vis[new_x][new_y] = 1;
                    q.push({new_x,new_y});
                    
                    if(new_x == X && new_y == Y)
                    {
                        return dis[new_x][new_y];
                    }
                }
            }
        }
        
        return -1;
    }
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y)
    {
        if(A[0][0] == 0){
            return -1;
        }
        else if(X == 0 && Y == 0){
            return 0;
        }
        return bfs(N,M,A,X,Y);
    }
};