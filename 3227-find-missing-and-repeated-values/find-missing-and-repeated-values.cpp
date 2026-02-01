class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int s1=0,s2=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;++j)
            {
                s1+=grid[i][j];
                s2+=(long)grid[i][j]*grid[i][j];
            }
        }
        long  n_squared=n*n;
        int val1= n_squared*(n_squared+1)/2-s1;
        int val2=(n_squared+1)*(2*n_squared+1)*n_squared/6 -s2;
        val2=(val2/val1);
        vector<int> ans={(val2-val1)/2,(val2+val1)/2};

        return ans;
    }
};