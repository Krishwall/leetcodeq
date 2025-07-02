class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        for(int j=0;j<m;++j)
        dp[0][j]=matrix[0][j];
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                
                 int top=INT_MAX,top_left=INT_MAX,top_right=INT_MAX;
                    
                        top=dp[i-1][j]+matrix[i][j];
                        if(j>0) top_left=dp[i-1][j-1]+matrix[i][j];
                        if(j<m-1) top_right=dp[i-1][j+1]+matrix[i][j];
                

                dp[i][j]=min(top,min(top_left,top_right));
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};