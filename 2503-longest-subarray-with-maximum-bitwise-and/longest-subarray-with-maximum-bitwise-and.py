class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        max_and=ans=maxlen=0
        for num in nums:
            if max_and<num:
                max_and=num
                ans=maxlen=0
            if max_and==num:
                maxlen+=1
            else :
                maxlen=0
            ans=max(ans,maxlen)
        return ans
            