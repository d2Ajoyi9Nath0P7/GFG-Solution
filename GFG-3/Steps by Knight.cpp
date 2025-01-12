class Solution 
{
    int dx[8] = {-2,-1,+1,+2,+2,+1,-1,-2};
    int dy[8] = {+1,+2,+2,+1,-1,-2,-2,-1};
    
    bool isValid(int x,int y,int N,vector<vector<int>>&vis)
    {
        if(x >= 1 && x <= N && y >= 1 && y <= N && vis[x][y] == 0)
        {
            return true;
        }
        return false;
    }
    
    public:
    
    int solve(int x1,int y1,int tX1,int tY1,int N)
    {
        vector<vector<int>>vis(N+1,vector<int>(N+1,0));
	    vector<vector<int>>dis(N+1,vector<int>(N+1,0));
	    
        int result = 0;
        queue<pair<int,int>>q;
        q.push({x1,y1});
        dis[x1][y1] = 0;
        vis[x1][y1] = 1;
        
        while(!q.empty())
        {
            pair<int,int>frnt = q.front();
            
            int row = frnt.first;
            int col = frnt.second;
       
            q.pop();
            
            if(row == tX1 && col == tY1)
            {
                result = dis[row][col];
                return result;
            }
            
            for(int i = 0 ; i < 8 ; i++)    
            {
                int newRow = row + dx[i];
                int newCol = col + dy[i];
                if(isValid(newRow,newCol,N,vis))
                {
                    vis[newRow][newCol] = 1;
                    q.push({newRow,newCol}); 
                    dis[newRow][newCol] = dis[row][col] + 1;
                }
            }
        }
    }
    
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int i = KnightPos[0];
	    int j = KnightPos[1];
	    int tX1 = TargetPos[0];
	    int tY1 = TargetPos[1];
	    
	    return solve(i,j,tX1,tY1,N);
	}
};