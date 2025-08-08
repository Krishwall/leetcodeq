class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] || grid[n-1][n-1]) return -1;

        vector<int> drow = {-1,-1,-1,0,0,1,1,1};
        vector<int> dcol = {-1,0,1,-1,1,-1,0,1};

        queue<pair<int,int>> q;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        dist[0][0] = 1; 
        q.push({0,0});

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == n-1 && c == n-1) return dist[r][c];

            for (int i = 0; i < 8; i++) {
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    grid[nr][nc] == 0 && dist[r][c] + 1 < dist[nr][nc]) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return -1;
    }
};
