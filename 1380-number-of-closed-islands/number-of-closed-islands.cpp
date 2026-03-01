class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int u) {
        if(parent[u] != u)
            parent[u] = findUPar(parent[u]);
        return parent[u];
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int total = n * m;
        int boundary = total;

        DisjointSet ds(total + 1);

        auto id = [&](int i, int j) {
            return i * m + j;
        };

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 0) {
                    int curr = id(i, j);

                    // If on boundary
                    if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                        ds.unionByRank(curr, boundary);
                    }

                    // Down
                    if(i + 1 < n && grid[i+1][j] == 0)
                        ds.unionByRank(curr, id(i+1, j));

                    // Right
                    if(j + 1 < m && grid[i][j+1] == 0)
                        ds.unionByRank(curr, id(i, j+1));
                }
            }
        }

        int boundaryParent = ds.findUPar(boundary);

        unordered_set<int> st;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    int p = ds.findUPar(id(i,j));
                    if(p != boundaryParent)
                        st.insert(p);
                }
            }
        }

        return st.size();
    }
};