class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();

        vector<vector<int>> dp(n,vector<int>(m,0));

        for(int i=0;i<n;++i)
        {
            for(int j=0;j<triangle[i].size();++j)
            {
                if(i==0 && j==0) dp[i][j]=triangle[i][j];
                else
                {   int left=INT_MAX,right=INT_MAX,up=INT_MAX;
                    if(j<triangle[i-1].size()) up=dp[i-1][j]+triangle[i][j];
                    if(j>=1 ) left=dp[i-1][j-1]+triangle[i][j];
                  
                    dp[i][j]=min(left,up);
                }
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};