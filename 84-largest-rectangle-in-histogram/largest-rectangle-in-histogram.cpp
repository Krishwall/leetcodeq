class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nse= nsee(heights,n);
        vector<int> pse= psee(heights,n);
        int r,l,max_rect=0;
        for(int i=0;i<n;++i)
        {r=nse[i];
        l=pse[i];
         max_rect=max(max_rect,(r-l-1)*heights[i]);

        }
    return max_rect;
    }
    vector<int> nsee(vector<int>& arr,int n ){
        stack<int> st ;
        vector<int> res(n); 
        for(int r=n-1;r>=0;--r){
            while(!st.empty() && arr[st.top()]>= arr[r])
            st.pop();
            
                if(st.empty())
                    res[r]=n;
                else
                    res[r]=st.top();

            st.push(r);
            }
        
    return res;
    }
    vector<int> psee(vector<int>& arr , int n ){
        stack<int> st ;
        vector<int> res(n); 
        for(int l=0;l<n;++l){
            while(!st.empty() && arr[st.top()]> arr[l])
            st.pop();
            
                if(st.empty())
                    res[l]=-1;
                else
                    res[l]=st.top();

            st.push(l);
            }
        
    return res;}
};