class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        def fact(f):
            fa=1
            for i in range(2,f+1):
                fa*=i
            return fa
        return fact(m+n-2)//(fact(m-1)*fact(n-1))
