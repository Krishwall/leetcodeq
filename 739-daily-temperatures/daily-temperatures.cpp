class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        int n=temperatures.size();
        vector<int> ans(n,0);

        for(int i=n-1;i>=0;i--)
        {      
            int curr=temperatures[i];
            
            
            while(!st.empty() && st.top().first<=curr)
                {
                    
                    st.pop();
                }
            
            if(!st.empty())
            ans[i]=st.top().second-i;
            st.push({curr,i});
        }
        return ans;
    }
};