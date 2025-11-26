class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        const int MOD =1e9+7;

       
       vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k,0)));

        dp[0][0][grid[0][0]%k]=1;

        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (i ==0 && j==0) continue; 

                for (int r=0;r<k;++r) {
                    long long ways = 0;

                    if (i>0) {
                        ways+= dp[i-1][j][r];
                    }
                    if (j>0) {
                        ways+=dp[i][j-1][r];
                    }

                    if (ways>0) {
                        int newR=(r+grid[i][j])%k;
                        dp[i][j][newR]=(dp[i][j][newR]+ways) % MOD;
                    }
                }
            }
        }

        return dp[n-1][m-1][0];
    }
};
