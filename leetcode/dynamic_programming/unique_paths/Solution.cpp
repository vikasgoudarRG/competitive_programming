class Solution {
public:
    int uniquePaths(int m, int n) {
        return dp_algo(m, n);
    }

    // DP
    // Time Complexity O(m * n)
    // Space Complexity O(n)
    int dp_algo(int m, int n) {
        vector<int> dp(n, 0);

        for (int col = 0; col < n; ++col) {
            if (col == 0) dp[0] = 1;
            else dp[col] = dp[col - 1];
        }

        for (int row = 1; row < m; ++row) {
            for (int col = 1; col < n; ++col) {
                dp[col] += dp[col - 1];
            }
        }
        return dp[n - 1];
    }
}