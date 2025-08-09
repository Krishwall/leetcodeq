class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n= heights.size();
        int m=heights[0].size();
        vector<vector<int>> effort(n,vector<int>(m,INT_MAX));

        priority_queue<vector<int>,vector<vector<int>>, greater<>> pq;
        effort[0][0]=0;
        pq.push({0,0,0});
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!pq.empty())
        {
            auto it=pq.top();
            int diff=it[0];
            int r=it[1];
            int c=it[2];
            pq.pop();

            if(r==n-1 && c==m-1 ) return diff;
            if(diff>effort[r][c]) continue;
            for(int i=0;i<4;++i)
            {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m )
                {   
                    int newEffort= max(abs(heights[r][c]-heights[nrow][ncol]),diff);
                if(newEffort<effort[nrow][ncol]){
                    effort[nrow][ncol]=newEffort;
                    pq.push({newEffort,nrow,ncol});

                }
                }
            }
        }

        return -1;
    }
};