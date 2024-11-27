class Solution:
    def findChampion(self, grid: List[List[int]]) -> int:
        l=len(grid)
        a=[0]*l

        for i in range(l):
            a[i]=sum(grid[i])
        return a.index(max(a))