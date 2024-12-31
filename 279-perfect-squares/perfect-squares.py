class Solution:
    def numSquares(self, n: int) -> int:
        dp=[9999]*(n+1)
        dp[0]=0
        a=1
        while a*a <=n:
            sq=a*a
            for i in range(sq,n+1):
                dp[i]=min(dp[i-sq]+1,dp[i])
            a+=1
        return dp[n]

        
