class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> visited(n,0);
        int provinces=0;
        for(int i=0;i<n;++i)
        {
            
                if(!visited[i])
                   { dfs(isConnected,visited,i);
                   provinces++;}
            
        }
        return provinces;
    }
    void dfs(vector<vector<int>>& isConnected,vector<int>& visited,int node)

    {   
        visited[node]=1;

        for(int j=0;j<isConnected.size();++j)
        {
            if(isConnected[node][j]==1 && !visited[j]){
                dfs(isConnected,visited,j);
            }
        }
        

    }
};