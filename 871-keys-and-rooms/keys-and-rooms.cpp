class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> vis(n,false);
        vis[0]=1;
        dfs(0,vis,rooms);
        for(bool a: vis)
            if(a==false) return false;
        return true;
    }

    void dfs(int node, vector<bool>& vis,vector<vector<int>>& rooms)
    {   
        
        vis[node]=1;

        for(auto &a:rooms[node])
        {
            if(vis[a]!=1)
                dfs(a,vis,rooms);
        }
        
    }
};