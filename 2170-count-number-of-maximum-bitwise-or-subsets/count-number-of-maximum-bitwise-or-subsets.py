class Solution:
        def helper(self,nums,index,orr,max_or,count):
            if orr==max_or:
                count[0]+=1
            for i in range(index,len(nums)):
                self.helper(nums,i+1,nums[i] | orr,max_or,count)
        def countMaxOrSubsets(self, nums: List[int]) -> int:
            count=[0]
            max_or=0
            for k in nums:
                max_or|=k
            self.helper(nums,0,0,max_or,count)

            return count[0]


