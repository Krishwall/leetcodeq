class Solution:

    def countPrimes(self, n: int) -> int:
        def sqrt_help(sq,d,a):
            if sq<=a:
                return sqrt_help(sq+d,d+2,a)
            return d
        a=[1 for i in range(n)]
        if n>2:
            a[0]=0
            a[1]=0
            for i in range(2,sqrt_help(1,3,n)//2):
                if a[i]==1:
                    for j in range(i*i,n,i):
                       
                            a[j]=0
            return sum(a)
        return 0

