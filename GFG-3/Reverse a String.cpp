//User function Template for C++
class Solution
{
    public:
    string reverseWord(string str)
    {
        stack<char>st;
        for(int i = 0 ; i < str.size() ; i++){
            st.push(str[i]);
        }
        string str2 = "";
        while(!st.empty())
        {
            char ch = st.top();
            str2.push_back(ch);
            st.pop();
        }
        return str2;
    }
};
