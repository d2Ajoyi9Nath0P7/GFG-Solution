//User function template for C++
class Solution{
public:	
	
	int isPalindrome(string S)
	{
	    int left = 0,right = S.size()-1;
	    int chk = 0;
	    while(left <= right)
	    {
	        if(S[left] == S[right])
	        {
	            left++;
	            right--;
	        }
	        else{
	            return 0;
	        }
	    }
	    return 1;
	}

};