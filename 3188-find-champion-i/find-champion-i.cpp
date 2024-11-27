class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int len=grid.size();

        for (int i=0;i<len;++i)
            if (accumulate(grid[i].begin(),grid[i].end(),0)==(len-1))
                return i;
        return 0;
    }
};