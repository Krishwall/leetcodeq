
class Solution {
public:
    vector<int> rank,parent;

    int findUpar(int node)
    {
        if(node==parent[node])
            return node;
        return parent[node]=findUpar(parent[node]);

    }

    bool unionByRank(int& u,int& v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);;
        if(ulp_u==ulp_v)
            return false;
        if(rank[ulp_u]<rank[ulp_v])
            parent[ulp_u]=ulp_v;

        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;

        }
        else
            {
                parent[ulp_v]=ulp_u;
                rank[ulp_u]++;
            }
    return true;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        
        int n=edges.size();
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }
        vector<int> indegree(n+1,-1);
        int e1=-1,e2=-1;

        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];

            if(indegree[v]==-1){
                indegree[v]=i;
            }
            else
            {
                e1=indegree[v];
                e2=i;
                break;
            }
        }
        int u_x,u_y;
        for(int i=0;i<n;i++)
        {   
            if(i==e2) continue;
            int u=edges[i][0];
            int v=edges[i][1];
            if(!unionByRank(u,v))
               {
                if(e1==-1)
                    return edges[i];
                return edges[e1];
               }
            
        }
        return edges[e2];
    }
};