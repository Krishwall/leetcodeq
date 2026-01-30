class Solution {
public:
    int longestValidParentheses(string s) {
        int  maxlen=0;
        stack<int> st;
        st.push(-1);
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(i);

            }
            else if(s[i]==')')
            {   
                st.pop();
                if(!st.empty())
                {int currlength=0;
                currlength=i-st.top();
                maxlen=max(maxlen,currlength);
                }

                else 
                {
                    st.push(i);
                }


            }

        }
        return maxlen;
    }   
};