class DisjointSet
{   
    public:
    vector<int> parent,rank;
    DisjointSet(int n)
    {
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int ulp(int x)
    {
        if(parent[x]!=x)
            return parent[x]=ulp(parent[x]);
        return parent[x];
    }
    void unionByRank(int u, int v)
    {
        int ulp_u=ulp(u);
        int ulp_v=ulp(v);
        if(ulp_u==ulp_v)
        return ;
        if(rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u])
        {
            parent[ulp_v]=ulp_u;
        }
        else
        {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        DisjointSet ds(26);
        for(auto& a:equations)
        {
            

            if(a[1]=='=')
            {  
                ds.unionByRank((a[0]-'a'),(a[3]-'a'));
            }
            
        }
        for(auto& a:equations){
            if(a[1]=='!')
            {
                if(ds.ulp(a[0]-'a')==ds.ulp(a[3]-'a'))
                    return false;
            }
        }
        return true;
    }
};