class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=1e9+7;
        vector<vector<pair<int,int>>> adjl(n);
        vector<long long> dist(n,LONG_MAX);
        vector<int> ways(n,0);
        for(auto& it: roads)
        {
            adjl[it[0]].push_back({it[1],it[2]});
            adjl[it[1]].push_back({it[0],it[2]});
        }
        dist[0]=0;
        ways[0]=1;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> q;
        q.push({0,0});
      
        while(!q.empty())
        {
            auto[cost,node]=q.top();
            q.pop();

            
            if (cost > dist[node]) continue;

            for(auto& it:adjl[node])
            {
                int adjNode=it.first;
                int edW=it.second;

                if(dist[adjNode]>edW+cost)
                {
                    dist[adjNode]=(edW+cost);
                    q.push({dist[adjNode],adjNode});
                    ways[adjNode]=ways[node];

                }
                else if(dist[adjNode]==(edW+cost))
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
            }

        }

        return ways[n-1]%mod;
    }
};