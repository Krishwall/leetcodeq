class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();

        // vector<vector<int>> dp(n,vector<int>(m,0));
        vector<int> prev(m,0);
        for(int i=0;i<n;++i)
        {   vector<int> cur(m,0);
            for(int j=0;j<triangle[i].size();++j)
            {
                if(i==0 && j==0) cur[j]=triangle[i][j];
                else
                {   int left=INT_MAX,up=INT_MAX;
                    if(j<triangle[i-1].size()) up=prev[j]+triangle[i][j];
                    if(j>=1 ) left=prev[j-1]+triangle[i][j];
                  
                    cur[j]=min(left,up);
                }
            }
            prev=cur;
        }
        return *min_element(prev.begin(),prev.end());
    }
};