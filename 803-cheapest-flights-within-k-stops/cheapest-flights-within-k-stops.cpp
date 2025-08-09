class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> adjl(n);
        for(auto it:flights)
        {
            adjl[it[0]].push_back({it[1],it[2]});
        }

        vector<int> dist(n,INT_MAX);
        using T=tuple<int,int, int>;
        queue<T> q;
        q.push({0,src,0});
        dist[src]=0;
        while(!q.empty())
        {
            auto [stops,node,cost]= q.front();
            q.pop();
            if(stops>k) continue;
            
            for(auto it:adjl[node]){
                int adjNode=it.first;
                int edW=it.second;
                if(dist[adjNode] >edW+cost && stops<=k)
                {dist[adjNode]=edW+cost;
                 q.push({stops+1,adjNode,dist[adjNode]});
                 }
            }

        }
        
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};