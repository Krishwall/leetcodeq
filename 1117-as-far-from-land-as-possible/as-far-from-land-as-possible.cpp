class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q;
        
        int n=grid.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    q.push({i,j});
            }
        }

        if(q.empty() || q.size()==n*n)
        return -1;

        int distance=-1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        

        while(!q.empty())
            {
                int size=q.size();
                while(size--)
                {
                    auto [x,y]=q.front();
                    q.pop();

                    for(int i=0;i<4;i++)
                    {
                        int nr=x+delrow[i];
                        int nc=y+delcol[i];
                        if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0)
                            {
                                grid[nr][nc]=1;
                                q.push({nr,nc});
                            }
                    }

                }
                distance++;

            }
            
            
            return distance;

        
    }
};