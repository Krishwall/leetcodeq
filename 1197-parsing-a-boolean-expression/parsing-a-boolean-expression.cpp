class Solution {
public:
    bool parseBoolExpr(string expression) {
        
        stack<char> st;

        for(auto a:expression)
        {
            if(a==',' || a=='(')
                continue;

            if(a!=')' )
            st.push(a);

            else if(a==')')
            {
                bool hasTrue=false;bool hasFalse=false;

                while(st.top()!='!' && st.top()!='&' && st.top()!='|')
                {
                    char topValue=st.top();
                    st.pop();
                    if(topValue=='t') hasTrue=true;
                    if(topValue=='f') hasFalse=true;
                }

                char op=st.top();
                st.pop();
                if(op=='!')
                st.push(hasTrue?'f':'t');
                else if(op=='&')
                st.push(hasFalse?'f':'t');
                else
                st.push(hasTrue?'t':'f');
            }
        }

        return st.top()=='t';
    }
};