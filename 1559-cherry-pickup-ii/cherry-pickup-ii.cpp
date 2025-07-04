class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(m,vector<int>(m,0)));
        vector<vector<int>> front(m,vector<int>(m,0));
        vector<vector<int>> cur(m,vector<int>(m,0));
        for(int j1=0;j1<m;j1++)
        {
            for(int j2=0;j2<m;j2++)
            {
                if(j1==j2) front[j1][j2]=grid[n-1][j1];
                else 
                front[j1][j2]=grid[n-1][j1]+grid[n-1][j2];
            }
        }

        for(int i=n-2;i>=0;--i)
        {
            for(int j1=0;j1<m;++j1)
            {
                for(int j2=0;j2<m;++j2)
                {
                        int maxi=-1e8;
                        for(int dj1=-1;dj1<=1;++dj1)
                        {
                            for(int dj2=-1;dj2<=1;++dj2)
                            {
                                int value=0;
                                if(j1==j2) value=grid[i][j1];
                                else
                                value=grid[i][j1]+grid[i][j2];

                                if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m)
                                    value+=front[j1+dj1][j2+dj2];
                                else
                                    value+=-1e8;
                                maxi=max(maxi,value);
                            }
                        }
                    cur[j1][j2]=maxi;
                }
            }
            front=cur;
        }

        return front[0][m-1];
    }
};