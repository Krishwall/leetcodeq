class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        unordered_map<int,unordered_set<int>> adj;
        for(int i=0;i<pairs.size();i++)
        {
            adj[pairs[i][0]].insert(pairs[i][1]);
            adj[pairs[i][1]].insert(pairs[i][0]);
        }
        priority_queue<pair<int,int>> pq;
        for(auto& [node,neighbours]:adj)
        {
            pq.push(make_pair(neighbours.size(),node));
        }

        int totalNodes=pq.size();
        int result=1;
        unordered_set<int> visited;

        while(!pq.empty())
        {
            int currNode=pq.top().second;
            int degree=pq.top().first;
            pq.pop();

            int parent=-1;
            int parentDegree=INT_MAX;
            for(auto &neighbour:adj[currNode]){
                if(visited.count(neighbour)&& adj[neighbour].size()<parentDegree && adj[neighbour].size()>=degree){

                    parent=neighbour;
                    parentDegree=adj[neighbour].size();


                }
            }
            visited.insert(currNode);

            if(parent==-1)
            {
                if(degree!=totalNodes-1)
                    return 0;
                continue;
            }

            for(auto &neighbour:adj[currNode])
            {
                if(neighbour==parent) continue;
                if(!adj[parent].count(neighbour)) return 0;
            }
            if(degree==parentDegree)
                result=2;
        }
        return result;
    }
};