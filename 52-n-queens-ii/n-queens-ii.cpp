class Solution {
public:
    int ans = 0;

    int totalNQueens(int n) {
        vector<int> leftRow(n, 0), upperDiagonal(2*n-1, 0), lowerDiagonal(2*n-1, 0);
        solve(0, leftRow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }

    void solve(int col, vector<int>& leftRow, vector<int>& upperDiagonal,
               vector<int>& lowerDiagonal, int n)
    {
        if (col == n) {
            ans++;
            return;
        }

        for (int row = 0; row < n; row++) {
            if (!leftRow[row] &&
                !lowerDiagonal[row + col] &&
                !upperDiagonal[n - 1 + col - row])
            {
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                solve(col + 1, leftRow, upperDiagonal, lowerDiagonal, n);

                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }
};