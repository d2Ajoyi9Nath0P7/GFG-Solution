//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix)
	{
	   for(int i = 0 ; i < matrix.size() ;i++){
	       for(int j = 0 ; j < matrix.size() ;j++){
	           if(i == j)
	           {
	               matrix[i][j] = 0;
	           }
	           else if(matrix[i][j] == -1){
	               matrix[i][j] = 1e9;
	           }
	       }
	   }
	   
	   for(int via = 0 ; via < matrix.size() ; via++)
	   {
	        for(int i = 0 ; i < matrix.size() ;i++)
	        {
	            for(int j = 0 ; j < matrix.size() ;j++)
	            {
	                matrix[i][j] = min(matrix[i][j],matrix[i][via] + matrix[via][j]);           
	            }
	        }   
	    }
	    
	        for(int i = 0 ; i < matrix.size() ;i++)
	        {
	            for(int j = 0 ; j < matrix.size() ;j++)
	            {
	                if(matrix[i][j] == 1e9)
	                {
	                    matrix[i][j] = -1;
	                }
	            }
	        }
	}
};