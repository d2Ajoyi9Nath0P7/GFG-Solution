
class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char>st;
        int sz = x.size();
        
        for(int i = 0 ; i < sz ; i++)
        {
            if(x[i] == '[' || x[i] == '(' || x[i] == '{')
            {
                st.push(x[i]);
            }
            else{
                if(st.empty())
                {
                    return false;
                }
                else
                {
                    char ch = st.top();
                    st.pop();
                    if((x[i] == ')' && ch == '(') or (x[i] == '}' &&  ch == '{') or (x[i] == ']' &&  ch == '['))
                    {
                        continue;                           
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        
        while(st.empty())
        {
            return true;
        }
        return false;
    }

};