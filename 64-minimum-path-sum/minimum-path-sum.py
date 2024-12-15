class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        # grid[1][1]+=grid[0][0]+min(grid[1][0],grid[0][1])
        n=len(grid)
        m=len(grid[0])
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if i==0 and j==0:
                    continue
                if i==0 and j!=0:
                    grid[i][j]+=grid[i][j-1]
                elif j==0 and i!=0:
                    grid[i][j]+=grid[i-1][j]
                else :
                    grid[i][j]+=min(grid[i][j-1],grid[i-1][j])
        return grid[n-1][m-1]
        
       