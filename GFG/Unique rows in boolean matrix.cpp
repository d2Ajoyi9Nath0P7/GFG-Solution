class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
    {
        vector<vector<int>>rs;
        set<vector<int>>st;
        
        for(int i = 0 ; i < row ; i++){
            vector<int>temp;
            for(int j = 0 ; j < col ;j++)
            {
                temp.push_back(M[i][j]);   
            }
            if(st.find(temp) == st.end())
            {
                st.insert(temp);
                rs.push_back(temp);
            }
        }
        
        return rs;
    }
};