class Solution {
  public:
    int search(int A[], int l, int h, int key) {
    
        int left = l,right = h;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(A[mid] == key)
            {
                return mid;
            }
            else if(A[mid] >= A[left])
            {
                if(A[left] <= key && key <= A[mid])
                {
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            else{
                if(A[mid] <= key && key <= A[right])
                {
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};