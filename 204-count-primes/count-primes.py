class Solution:
    def countPrimes(self, n: int) -> int:
        a=[1 for i in range(n)]
        if n>2:
            a[0]=0
            a[1]=0
            for i in range(2,int(sqrt(n))+1):
                if a[i]==1:
                    for j in range(2,n//i+1):
                        if i*j<n:
                            a[i*j]=0
            return a.count(1)
        return 0

