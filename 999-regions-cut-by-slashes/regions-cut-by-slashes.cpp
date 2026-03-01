class Solution {
public:
        vector<int> parent;

        int find(int x)
        {
            if(parent[x]!=x)
            parent[x]=find(parent[x]);

            return parent[x];
        }
        void unite(int x,int y)
        {
            parent[find(x)]=find(y);
        }
    int regionsBySlashes(vector<string>& grid) {
        
        int n=grid.size();
        int total=4*n*n;
        parent.resize(total);

        for(int i=0;i<total;i++)
        {
            parent[i]=i;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int base=4*(i*n+j);
                char c=grid[i][j];

                if(c==' ')
                {
                    unite(base+0,base+1);
                    unite(base+1,base+2);
                    unite(base+2,base+3);
                }
                else if(c=='/')
                {
                    unite(base+0,base+3);
                    unite(base+1,base+2);
                }
                else
                {
                    unite(base+0,base+1);
                    unite(base+2,base+3);
                }

                if(i+1<n)
                {
                    int down=4*((i+1)*n + j);
                    unite(base+2,down+0);
                }
                if(j+1<n)
                {
                    int right=4*(i*n +(j+1));
                    unite(base+1,right+3);
                }

            }
        }

        int regions=0;
        for(int i=0;i<total;i++)
        {
            if(parent[i]==i)
                regions++;
        }

        return regions;


    }
};