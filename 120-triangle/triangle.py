class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        j=0
        
        n=len(triangle)
        if n==1: return triangle[0][0]
        for i in range(1,n):
            triangle[i][0]=triangle[i][0]+triangle[i-1][0]
            lencol=len(triangle[i])
            triangle[i][lencol-1]=triangle[i][lencol-1]+triangle[i-1][len(triangle[i-1])-1]

        for i in range(2,n):
            for j in range(1,len(triangle[i])-1):
                triangle[i][j]+=min(triangle[i-1][j-1],triangle[i-1][j])
        return min(triangle[n-1])
        
