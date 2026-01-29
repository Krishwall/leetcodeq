class Solution {
    private:
    
    void floydwarshall(vector<vector<int>>& graph,int n)
    {   // graph

        for(int i=0;i<n;i++)
            graph[i][i]=0;

        for (int k = 0; k < n; k++) {

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                if(graph[i][k] != 1e8 && graph[k][j]!= 1e8)
                graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
            }
        }
    }
    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

        
        vector<vector<int>> graph(26,vector<int>(26,1e8));

        for(int j=0;j<original.size();j++)
        {
            graph[original[j]-'a'][changed[j]-'a']=min(cost[j], graph[original[j]-'a'][changed[j]-'a']);

        }
        int n=original.size();
        floydwarshall(graph,26);
        long long mincost=0;
        for(int i=0;i<source.size();i++)
        {   
            if(graph[source[i]-'a'][target[i]-'a'] == 1e8)
            return -1;
            mincost+=graph[source[i]-'a'][target[i]-'a'];
        }
        return mincost;

        
    

    }
};