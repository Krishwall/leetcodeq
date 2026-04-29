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
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && st.top()<arr[i])
            {
                int a=st.top();
                st.pop();
                res+=a*min(st.top(),arr[i]);
            }
            st.push(arr[i]);
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