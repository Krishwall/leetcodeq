class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> mat(n,vector<int>(m) );

        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                mat[i][j]=matrix[i][j]-'0';
        
        for(int j=0;j<m;++j)
        {int sum=0;
            for(int i=0;i<n;++i)
            {
                sum+=mat[i][j];
                if(mat[i][j]==0)
                    sum=0;
                    mat[i][j]=sum;
            }
        }
        int maxArea=0;
        for(int i=0;i<n;++i)
        {
            maxArea=max(maxArea,largestRectangleArea(mat[i]));
        }
    return maxArea;
    }
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n=heights.size();
        int pse,nse,ele,maxRect=0;
        for(int i=0;i<n;++i)
            {
                while(!st.empty() && heights[i]<heights[st.top()])
                {
                    ele=st.top();
                    st.pop();
                    nse=i;
                    pse=st.empty()?-1:st.top();
                    maxRect=max(maxRect,(nse-pse-1)*heights[ele]);
                }   
                st.push(i);
            }
        while(!st.empty())
        {
            nse=n;
            ele=st.top();st.pop();
            pse=st.empty()?-1:st.top();
            maxRect=max(maxRect,(nse-pse-1)*heights[ele]);
        }
        return maxRect;





  }

};