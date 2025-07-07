class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(), s2.end());

        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            int prev_diag = 0;  // This represents dp[j-1] from the previous row
            for (int j = 1; j <= n; ++j) {
                int temp = dp[j];  // Save current dp[j] before overwriting
                if (s[i - 1] == s2[j - 1])
                    dp[j] = 1 + prev_diag;
                else
                    dp[j] = max(dp[j], dp[j - 1]);
                prev_diag = temp;
            }
        }

        return dp[n];
    }
};
