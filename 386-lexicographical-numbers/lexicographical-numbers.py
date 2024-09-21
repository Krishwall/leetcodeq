class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        nums=[str(i+1) for i in range(n)]
        nums=sorted(nums)
        nums=[int(i) for i in nums]
        return nums
        
        

        