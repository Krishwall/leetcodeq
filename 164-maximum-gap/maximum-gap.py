class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        if len(nums)<2:
            return 0
        maxi=0
        nums=sorted(nums)
        for i in range(0,len(nums)-1):
            maxi=max(nums[i+1]-nums[i],maxi)
        return maxi
