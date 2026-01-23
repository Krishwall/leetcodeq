class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int count=0;
        stack<char> st;
        for(auto &ch:s)
        {
            if(ch=='(')
             st.push(ch);

            else {
                if(st.empty())
                    count++;
                else 
                    st.pop();

            }

        }
        
        while(!st.empty())
        {
            count++;
            st.pop();
        }
        return count;

    }
};