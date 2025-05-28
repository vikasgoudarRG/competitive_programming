// https://leetcode.com/problems/minimum-path-sum/?envType=study-plan-v2&envId=dynamic-programming

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // 1d appraoch, with perspective from goal
    int m = grid.size();
    int n = grid[0].size();
    vector<int> dp(n);
    for (int i = m-1; i >= 0; --i) {
        for (int j = n-1; j >=0; --j) {
            if (i == m-1 && j != n-1) {
                dp[j] = grid[i][j] + dp[j+1];
            }
            else if (i != m-1 && j == n-1) {
                dp[j] = grid[i][j] + dp[j];
            }
            else if (i != m-1 && j != n-1) {
                dp[j] = grid[i][j] + min(dp[j], dp[j+1]);
            }
            else dp[j] = grid[i][j];
        }
    }
    return dp[0];
    
    /*
        // 1d approach, with perspective from source
    int m = grid.size();
    int n = grid[0].size();

    vector<int> dp(n);
    dp[0] = grid[0][0];
    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i-1] + grid[0][i];
    }

    for (int i = 1; i < m; ++i) {
        dp[0] += grid[i][0];
        for (int j = 1; j < n; ++j) {
            dp[j] = min(dp[j-1], dp[j]) + grid[i][j];
        }
    }
    return dp[n-1];
    */

    /*
        // 2d approach
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n));

    for (int row = 0; row < m; ++row) {
        for (int col = 0; col < n; ++col) {
            if (row == 0 && col == 0) {
                dp[0][0] = 0;
            }
            else if (row == 0) {
                dp[row][col] = dp[row][col-1] + grid[row][col-1];
            }
            else if (col == 0) {
                dp[row][col] = dp[row-1][col] + grid[row-1][col];
            }
            else {
                dp[row][col] = min(dp[row][col-1] + grid[row][col-1], dp[row-1][col] + grid[row-1][col]);
            }
        }
    }
    return dp[m-1][n-1] + grid[m-1][n-1];
    */

    /*
        // recursion and memoization
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return recur(m-1, n-1, dp, grid);
    */
    
    }

    /*
    int recur(int m, int n, vector<vector<int>>& dp, const vector<vector<int>>& grid) {
        if (m == 0 && n == 0) return grid[0][0];

        if (dp[m][n] > -1) return dp[m][n] + grid[m][n];
        if (m == 0) dp[m][n] = recur(m, n-1, dp, grid);
        else if (n == 0) dp[m][n] = recur(m-1, n, dp, grid);
        else dp[m][n] = min(recur(m, n-1, dp, grid), recur(m-1, n, dp, grid));

        return dp[m][n] + grid[m][n];
    }
    */
};
