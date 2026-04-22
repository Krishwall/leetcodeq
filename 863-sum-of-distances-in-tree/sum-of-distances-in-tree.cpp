class Solution {

    void dfs(vector<vector<int>> &adjl,int u,int p,vector<int> &d,vector<int> &s){
        s[u]=1;
        for(int v:adjl[u]){
            if(v==p)
                continue;
            d[v]=d[u]+1;
            dfs(adjl,v,u,d,s);
            s[u]+=s[v];
        }
    }

    void dfs2(vector<vector<int>> &adjl,int u,int p,int sumOfDistances,vector<int> &s,vector<int> &ans,int n)
    {
       ans[u]=sumOfDistances;
       for(int v:adjl[u]){
            if(v==p)
                continue;
            int sdv=sumOfDistances-s[v]+(n-s[v]);
            dfs2(adjl,v,u,sdv,s,ans,n);
       }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
    vector<vector<int>> adjl(n);
    for (auto &e : edges) {
        adjl[e[0]].push_back(e[1]);
        adjl[e[1]].push_back(e[0]);
    }
    vector<int> d(n,0),s(n,0);
    dfs(adjl,0,-1,d,s);
    int sumOfDistances  =0;
        for(int i=0;i<n;++i)
            sumOfDistances+=d[i];
    
    vector<int> ans(n,0);
    dfs2(adjl,0,-1,sumOfDistances,s,ans,n);

    return ans;
    // vector<int> answer(n, 0);

    
    // for (int i = 0; i < n; i++) {
    //     vector<bool> visited(n, false);
    //     queue<pair<int, int>> q; 
    //     q.push({i, 0});
    //     visited[i] = true;

    //     int totalDist = 0;

    //     while (!q.empty()) {
    //         auto [node, dist] = q.front();
    //         q.pop();

    //         totalDist += dist;

    //         for (int neighbor : adjl[node]) {
    //             if (!visited[neighbor]) {
    //                 visited[neighbor] = true;
    //                 q.push({neighbor, dist + 1});
    //             }
    //         }
    //     }

    //     answer[i] = totalDist;
    // }

    // return answer;
    }
};