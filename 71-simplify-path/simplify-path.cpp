class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string token;
        
        for (int i= 0; i<= path.size();i++) {
            if (i == path.size() || path[i] == '/') {
                if (token == "..") {
                    if (!st.empty()) st.pop();
                } 
                else if (!token.empty() && token != ".") {
                    st.push(token);
                }
                token.clear();
            } 
            else {
                token += path[i];
            }
        }

        string result;
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result.empty() ? "/" : result;
    }
};
