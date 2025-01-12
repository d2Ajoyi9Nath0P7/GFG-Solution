//User function Template for C++

class Solution{   
public:
    int minimumStep(int n){
        int cnt = 0;
        while(n > 1)
        {
            if(n % 3 == 0){
                n = n / 3;
                cnt++;
            }
            else{
                n--;
                cnt++;
            }
        }
        return cnt;
    }
};