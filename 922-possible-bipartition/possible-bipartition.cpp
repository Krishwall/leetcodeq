class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<vector<int>> adj(n + 1);
        
        
        for (auto &it : dislikes) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> color(n + 1, 0); // 0 = uncolored
        
        for (int i = 1; i <= n; i++) {
            
            if (color[i] != 0) continue;
            
            queue<int> q;
            q.push(i);
            color[i] = 1;
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                
                for (int neighbor : adj[node]) {
                    
                    if (color[neighbor] == 0) {
                        color[neighbor] = -color[node];
                        q.push(neighbor);
                    }
                    else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};