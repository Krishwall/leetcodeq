class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<int> dp(m,0); 

        for(int i=0;i<n;++i){
            vector<int> cur(m,0);
            for(int j=0;j<m;j++)
            {
                if(obstacleGrid[i][j]==1) cur[j]=0;
                else if(i==0 && j==0) cur[j]=1;
                else { int up=0,left=0;
                    if(i>0) up=dp[j];
                    if(j>0) left=cur[j-1];
                    cur[j]=(up+left);
                }
            }
            dp=cur;
        }
        return dp[m-1];
    }
};