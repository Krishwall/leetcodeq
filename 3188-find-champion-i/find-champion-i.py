class Solution:
    def findChampion(self, grid: List[List[int]]) -> int:
        
        a=[0]*len(grid)

        for i in range(len(grid)):
            a[i]=sum(grid[i])
        return a.index(max(a))