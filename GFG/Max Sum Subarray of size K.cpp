class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        K--;
        vector<long>pre_sum(N);
        /*if(Arr.size() == 1){
            return Arr[0];
        }*/
        pre_sum[0] = Arr[0];

        for(int i = 1 ; i < Arr.size(); i++){
            pre_sum[i] = pre_sum[i-1] + Arr[i]; 
        }
        vector<long>ans;
        ans.push_back(pre_sum[K]);
        for(int i = K+1 , j = 0; i < Arr.size() ; i++,j++)
        {
            long val = pre_sum[i] - pre_sum[j];
            ans.push_back(val);
        }
        long max_value = *max_element(ans.begin(),ans.end());
        return max_value;
    }
};