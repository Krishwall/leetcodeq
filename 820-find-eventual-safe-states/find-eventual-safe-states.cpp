class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> safenodes;
        vector<int> indegree(n,0);
        vector<vector<int>> revadj(n);
        for(int i=0;i<n;++i)
        {   
            for(auto it:graph[i])
            revadj[it].push_back(i);
        }

        for(int i=0;i<n;i++){
            for(auto it:revadj[i])
            {
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            safenodes.push_back(node);
            for(auto it:revadj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }

        sort(safenodes.begin(),safenodes.end());
        return safenodes;
    }
};