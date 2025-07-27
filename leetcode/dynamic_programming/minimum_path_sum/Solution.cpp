class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        return dp_algo(grid);
    }
    // DP
    // Time Complexity O(n * m)
    // Space Complexity O(m)
    int dp_algo(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n, 0);
        // row = 0
        for (int col = 0; col < n; ++col) {
            if (col == 0) dp[0] = grid[0][col];
            else {
                dp[col] = dp[col - 1] + grid[0][col];
            }
        }

        for (int row = 1; row < m; ++row) {
            dp[0] += grid[row][0];
            for (int col = 1; col < n; ++col) {
                dp[col] = min(dp[col], dp[col - 1]) + grid[row][col];
            }
        }
        return dp[n - 1];
    }
}