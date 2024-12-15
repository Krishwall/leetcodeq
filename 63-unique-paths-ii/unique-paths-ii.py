class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if not obstacleGrid or obstacleGrid[0][0] == 1:
            return 0
        m=len(obstacleGrid[0])
        n=len(obstacleGrid)

        dp=[0]*m
        dp[0]=1
        for i in range(n):
            for j in range(m):
                if obstacleGrid[i][j] :
                    dp[j]=0
                else:
                    if j>0:
                        dp[j]+=dp[j-1]
        
        return dp[-1]


           