// User function Template for C++

class Solution{
public:
    bool isSafe(int row,int col,vector<string>&board,int n)
    {
        int drow = row;
        int dcol = col;
        
        while(row >= 0 && col >= 0)
        {
            if(board[row][col] == 'Q')
            {
                return false;
            }
            row--;
            col--;
        }
        
        row = drow;
        col = dcol;
        
        while(col >= 0)
        {
            if(board[row][col] == 'Q')
            {
                return false;                
            }
            col--;
        }
        
        row = drow;
        col = dcol;
        
        while(row < n && col >= 0)
        {
            if(board[row][col] == 'Q')
            {
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    
    void chessSolve(int col,vector<string>&board,int n,vector<vector<int>>&vec)
    {
         if(col == n)
         {
            vector<pair<int,int>>vp;
            
            for(int i = 0 ; i < n; i++)
            {
                for(int j = 0 ; j < n ; j++)
                {
                    if(board[i][j] == 'Q')
                    {
                        vp.push_back({j+1,i+1});
                    }
                }
            }
            
            sort(vp.begin(),vp.end());//(1,2) (2,3) (3,1) (4,3)
            vector<int>temp;
            for(auto it : vp)
            {
                temp.push_back(it.second);
            }
            vec.push_back(temp);
            return;
         }
         
         for(int row = 0 ; row < n ; row++)
         {
            if(isSafe(row,col,board,n))
            {
                board[row][col] = 'Q';
                chessSolve(col+1,board,n,vec);
                board[row][col] = '.'; //backtrack
            }
         }
    }
    

    vector<vector<int>> nQueen(int n)
    {
        vector<string>board(n);
        vector<vector<int>>vec;
        
        string rw(n,'.');
        
        for(int i = 0 ; i < n ; i++)
        {
            board[i] = rw;
        }
        chessSolve(0,board,n,vec);
        return vec;
    }
};