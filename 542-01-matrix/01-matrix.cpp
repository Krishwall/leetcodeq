class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9)); // large initial value

        // First pass: top-left to bottom-right
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    if(i > 0)
                        dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                    if(j > 0)
                        dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }

        // Second pass: bottom-right to top-left
        for(int i = n - 1; i >= 0; --i) {
            for(int j = m - 1; j >= 0; --j) {
                if(i < n - 1)
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                if(j < m - 1)
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
            }
        }

        return dist;
    }
};
