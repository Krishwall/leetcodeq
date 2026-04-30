class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (auto& a : tokens) {
            if (a=="+" || a=="-" || a=="*" || a=="/") {
                int b= st.top();st.pop();
                int a1= st.top();st.pop();

                if (a=="+") st.push(a1+b);
                else if (a=="-") st.push(a1-b);
                else if (a=="*") st.push(a1*b);
                else st.push(a1/b);
            } 
            else {
                st.push(stoi(a));  
            }
        }

        return st.top();
    }
};