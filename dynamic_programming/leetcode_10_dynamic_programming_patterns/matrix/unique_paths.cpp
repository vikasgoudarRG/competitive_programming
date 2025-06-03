// https://leetcode.com/problems/unique-paths/?envType=study-plan-v2&envId=dynamic-programming

class Solution {
public:
    int uniquePaths(int m, int n) {
            // 1d array approach
        // space optimized version of 2d approach since we only need the previous row
        if (m > n) {
            int temp = m;
            m = n;
            n = temp;
        }
        vector<int> dp(m, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                dp[j] += dp[j-1];
            }
        }
        return dp[m-1];


            // math approach
        // overall we need to make m-1 + n-1 moves (down + right displacement) = m + n - 2 moves
        // so problem becomes a combinatorial approach to choosing down and right moves
        // (m+n-2)C(m-1) = (m+n-2)C(n-1) = 
        //                  (m+n-1)!/( (m-1)! * (n-1)! )
        // now the problem is to use good algo to calculate factorials 


        /*
            // recursion + memoization
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return recur(m-1,n-1,dp);
        */

        /*
            // 2d array approach
        vector<vector<int>> dp(m, vector<int>(n, 1));
        dp[0][0] = 1;
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) { 
                // search up
                if (row - 1 >= 0) {
                    dp[row][col] += dp[row-1][col];
                }
                // search left
                if (col - 1 >= 0) {
                    dp[row][col] += dp[row][col-1];
                }
            }
        }
        return dp[m-1][n-1];
        */
    }
    
    /*
    int recur(int m, int n, vector<vector<int>>& dp) {
        if (m == 0 || n == 0) return 1;
        if (dp[m][n] > -1) return dp[m][n];
        dp[m][n] = recur(m-1,n,dp) + recur(m, n-1, dp);
        return dp[m][n];
    }
    */
};
