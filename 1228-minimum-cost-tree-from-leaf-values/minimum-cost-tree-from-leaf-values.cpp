class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        if(n==1)
            return arr[0];
        if(n==2)
            return arr[0]*arr[1];
        stack<int> st;
        st.push(INT_MAX);
        int res=0;
        for(int& curr:arr)
        {
            while(!st.empty() && st.top()<curr)
            {
                int a=st.top();
                st.pop();
                res+=a*min(st.top(),curr);
            }
            st.push(curr);
        }

        while(st.size()>2)
        {
            int mid=st.top();
            st.pop();
            res+=mid*st.top();
        }
        return res;
    }
};