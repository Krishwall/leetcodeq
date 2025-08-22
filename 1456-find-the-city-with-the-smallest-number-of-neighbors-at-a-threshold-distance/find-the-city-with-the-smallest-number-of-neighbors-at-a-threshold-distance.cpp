class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int intmax=1e9;
        vector<vector<int>> dist(n,vector<int>(n,intmax));
        for(int i=0;i<edges.size();++i)
        {
            dist[edges[i][0]][edges[i][1]]=edges[i][2];
            dist[edges[i][1]][edges[i][0]]=edges[i][2];
        }

        for(int i=0;i<n;++i)
            { dist[i][i]=0;
            }


        for(int via =0;via<n;++via)
        {
            for(int i=0;i<n;++i)
            {
                for(int j=0;j<n;++j)
                {   
                    
                    dist[i][j]=min(dist[i][j],dist[i][via]+dist[via][j]);
                }
            }
        }

        int cityWithFewestReachable=-1;
        int fewestReachableCount=n;

        for(int i=0;i<n;i++)
        {   int reachableCount=0;
            for(int j=0;j<n;++j)
            {
                if(i==j) continue;

                if(dist[i][j]<=distanceThreshold)
                    reachableCount++;
            }

            if(reachableCount<=fewestReachableCount)
                {fewestReachableCount=reachableCount;
                cityWithFewestReachable=i;}
        }
        return cityWithFewestReachable;

    }
};