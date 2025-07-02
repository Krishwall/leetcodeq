class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> prevRow(m,-1);

        for(int i=0;i<n;++i)
        {   vector<int> cur(m,-1);
            for(int j=0;j<m;++j)
            {
                if (i==0 && j==0) cur[j]=grid[i][j];
                else{
                    int up=INT_MAX,left=INT_MAX;
                    if(i>0) up=prevRow[j] + grid[i][j];
                    if(j>0) left=cur[j-1]+grid[i][j];
                    cur[j]=min(up,left);
                }
            }
            prevRow=cur;
        }return prevRow[m-1];
    }
};