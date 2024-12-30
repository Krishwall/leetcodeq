class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<int> dp(matrix[0].begin(),matrix[0].end());
        int n = matrix.size();
        for (int i=1;i<n;i++)
            {
                vector<int> new1(n,0);
                for(int j=0;j<n;++j)
                {
                    if (j==0)
                        new1[j]=matrix[i][j] + min(dp[j], dp[j + 1]);
                    else if (j==n - 1)
                        new1[j]=matrix[i][j] + min(dp[j], dp[j - 1]);
                    else
                        new1[j] = matrix[i][j] + min({dp[j], dp[j - 1], dp[j + 1]});
                }
               dp=new1;
            }
            
        return *min_element(dp.begin(), dp.end());
    }
};