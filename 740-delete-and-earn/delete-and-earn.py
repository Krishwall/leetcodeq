class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        nums.sort()
        n=max(nums)
        sums=[0]*(n+1)
        dp=[0]*(n+1)
        for num in nums:
            sums[num]+=num
        dp[0]=0
        dp[1]=sums[1]

        for i in range(1,n):
            dp[i+1]=max(sums[i+1]+dp[i-1],dp[i])

        return dp[n]

        
