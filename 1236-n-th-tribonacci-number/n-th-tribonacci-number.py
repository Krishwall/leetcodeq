class Solution:
    def tribonacci(self, n: int) -> int:
        F=[0]*(n+3)

        F[0]=0
        F[1]=1
        F[2]=1

        if n<3:
            return F[n]
        for i in range(2,n):
            F[i+1]=F[i-2]+F[i-1]+F[i]
        return F[n]