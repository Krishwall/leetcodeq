
class Solution:
    def climbStairs(self, n: int) -> int:
        count=0
        l =n//2 
        if n%2==0:
            m=0
        else:
            m=1
        for i in range(l+1):
            count+=math.factorial(l+m)//(math.factorial(l)*math.factorial(m))
            m+=2
            l-= 1
        return count