class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& state) {
        if (state[node] == 1) return false; // in recursion → cycle
        if (state[node] == 2) return true;  // already known safe

        state[node] = 1; // mark as visiting
        for (int neighbor : graph[node]) {
            if (!dfs(neighbor, graph, state)) return false;
        }

        state[node] = 2; // mark as safe
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0);  // 0: unvisited, 1: visiting, 2: safe
        vector<int> safenodes;

        for (int i = 0; i < n; ++i) {
            if (dfs(i, graph, state)) {
                safenodes.push_back(i);
            }
        }

        return safenodes;
    }
};
