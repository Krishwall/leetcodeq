class Solution {
public:
    int dfs(int node, vector<vector<int>>& adj, vector<int>& informTime) {
        int maxTime = 0;

        for (int child : adj[node]) {
            maxTime = max(maxTime, dfs(child, adj, informTime));
        }

        return informTime[node] + maxTime;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);

        // Build tree
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                adj[manager[i]].push_back(i);
            }
        }

        return dfs(headID, adj, informTime);
    }
};