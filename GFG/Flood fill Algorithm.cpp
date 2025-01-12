class Solution {
public:

    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    
    bool isValid(int i,int j,int row,int col,int color,vector<vector<int>>&image,vector<vector<int>>&vis)
    {
        if(i >= 0 && i < row && j >= 0 && j < col && image[i][j] == color && vis[i][j] == 0)
        {
            return true;
        }
        return false;
    }

    vector<vector<int>>bfs(vector<vector<int>>&image,int sr,int sc,int newColor)
    {
        int row = image.size();
        int col = image[0].size();
        vector<vector<int>>vis(image.size(),vector<int>(image[0].size(),0));
        queue<pair<int,int>>q;
        
        int color = image[sr][sc];
        image[sr][sc] = newColor;
        vis[sr][sc] = 1;
        q.push({sr,sc});
        
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
                
                if(isValid(new_x,new_y,row,col,color,image,vis))
                {
                    image[new_x][new_y] = newColor;
                    vis[new_x][new_y] = 1;
                    q.push({new_x,new_y});
                }
            }
        }
        return image;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        return bfs(image,sr,sc,newColor);
    }
};