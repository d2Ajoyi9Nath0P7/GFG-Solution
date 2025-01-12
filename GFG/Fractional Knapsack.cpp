//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
bool cmp(Item a,Item b)
    {
        double x = (double)a.value / (double)a.weight;
        double y = (double)b.value / (double)b.weight;
        
        return x > y;
    }

class Solution
{
    
    
    public:
    //Function to get the maximum total value in the knapsack.
    
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr + n,cmp);
        int weight_left = W;
        double sum = 0.0;
        
        for(int i  = 0 ; i < n ; i++)
        {
            if(arr[i].weight <= weight_left)
            {
                weight_left -= arr[i].weight;
                sum += arr[i].value;
            }
            else
            {
                double ans = (double)weight_left * (((double)arr[i].value / (double)arr[i].weight));
                sum += ans;
                break;
            }
        }
        
        return sum;
    }
};