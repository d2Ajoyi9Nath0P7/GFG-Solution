//User function template for C++
class Solution{
public:	
	int search(int A[], int N){
	    int low = 0,high = N-2;
	    while(low <= high){
	        int mid = (low + high)>>1;
	        if(A[mid] == A[mid^1]){
	            low = mid + 1;
	        }
	        else{
	            high = mid - 1;
	        }
	    }
	    
	    return A[low];
	}
};