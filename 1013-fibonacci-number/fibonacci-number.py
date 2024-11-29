class Solution:
    def fib(self, n: int) -> int:
        if n==0:
            return 0
        F=[0]*(n+1)

        F[0]=0
        F[1]=1

        for i in range(1,n):
            F[i+1]=F[i]+F[i-1]
        return F[n]
        