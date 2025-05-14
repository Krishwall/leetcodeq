class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans=0;
        stack<int> st;

        for(int r=0; r<n; r++){
            while(!st.empty() && height[st.top()]<height[r]){
                int m=st.top();
                st.pop();

                if (st.empty()){
                break;
                }

                int l=st.top();
                int h= min(height[r]-height[m], height[l]-height[m]);
                int w= r-l-1;
                
                ans+=h*w;
            }
            st.push(r);
        }
        return ans;
    }
};