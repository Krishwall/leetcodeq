class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> adjl(n);
        vector<int> dist(n,INT_MAX);
        for(auto& it: times)
        {
            adjl[it[0]-1].push_back({it[1]-1,it[2]});
        }

        dist[k-1]=0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;
        q.push({0,k-1});
        while(!q.empty())
        {
            auto  [cost,node]=q.top();
            q.pop();
            if (cost > dist[node]) continue;

            for(auto& it:adjl[node])
            {
                int adjNode=it.first;
                int edW=it.second;

                if(dist[adjNode]>edW+cost)
                {
                    dist[adjNode]=edW+cost;
                    q.push({dist[adjNode],adjNode});

                }
            }

        }
        int ans=*max_element(dist.begin(),dist.end());

        return ans==INT_MAX?-1:ans;
    }
};