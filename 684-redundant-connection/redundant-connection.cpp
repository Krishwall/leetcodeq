class Solution {
    vector<int> par, size;

public:
    int findUPar(int num) {
        int curr_par = par[num];
        return par[num] = (curr_par == num) ? num : findUPar(curr_par);
    }

    void Union(int x, int y, vector<int>& res) {
        int a = findUPar(x);
        int b = findUPar(y);

        if (a == b) {
            res = {x, y};
            return;
        }

        if (size[a] > size[b]) {
            par[b] = a;
            size[a] += size[b];
        } else {
            par[a] = b;
            size[b] += size[a];
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        par.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }

        vector<int> res;

        for (auto& e : edges) {
            Union(e[0], e[1], res);
        }

        return res;
    }
};