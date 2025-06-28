// https://leetcode.com/problems/unique-paths-ii/description/?envType=study-plan-v2&envId=dynamic-programming

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // 1d array
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<long long> dp(n, 0);
    dp[n - 1] = obstacleGrid[m - 1][n - 1] == 0 ? 1 : 0;
    for (int i = m-1; i >= 0; --i) {
        if (obstacleGrid[i][n-1] == 1) {
            dp[n-1] = 0;
        }
        for (int j = n-2; j >= 0; --j) {
            if (obstacleGrid[i][j] == 1) {
                dp[j] = 0;
            }
            else {
                dp[j] += dp[j+1];
            }
        }
    }
    return dp[0];
    /*
        // 2d array
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<long long>> dp(m, vector<long long>(n,-1));
    for (int row = m-1; row >= 0; --row) {
        for (int col = n-1; col >= 0; --col) {
            if (obstacleGrid[row][col] == 1) dp[row][col] = 0;
            else if (row == m-1 && col != n-1) {
                dp[row][col] = dp[row][col+1];
            }
            else if (row != m-1 && col == n-1) {
                dp[row][col] = dp[row+1][col];
            }
            else if (row != m-1 && col != n-1) {
                dp[row][col] = dp[row][col+1] + dp[row+1][col];
            }
            else {
                dp[row][col] = 1;
            }

        }
    }
    return dp[0][0];
    */

    /*
        // recursion with memoization
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return recur(m-1, n-1, dp, obstacleGrid);
    */
    }

    /*
    int recur(int m, int n, vector<vector<int>>& dp, const vector<vector<int>>& obstacleGrid) {
        if (m < 0 || n < 0) return 0;
        if (obstacleGrid[m][n] == 1) return 0;
        if (m == 0 && n == 0) return 1;
        
        
        if (dp[m][n] > -1) return dp[m][n];

        dp[m][n] = recur(m-1, n, dp, obstacleGrid) + recur(m, n-1, dp, obstacleGrid);
        return dp[m][n];
    }
    */
};
