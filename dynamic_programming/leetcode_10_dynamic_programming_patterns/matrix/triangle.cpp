// https://leetcode.com/problems/triangle/?envType=study-plan-v2&envId=dynamic-programming

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
            // top-down 1d 
        int n = triangle.size();
        vector<int> dp = triangle[n-1];

        for (int row = n-2; row >= 0; --row) {
            for (int col = 0; col <= row; ++col) {
                dp[col] = min(dp[col], dp[col+1]) + triangle[row][col];
            }
        }
        return dp[0];
        
        
        /*
            // top-down in-place
        int n = triangle.size();
        for (int row = n - 2; row >= 0; --row) {
            for (int col = 0; col < row+1; col++) {
                triangle[row][col] = min(triangle[row+1][col], triangle[row+1][col+1]) + triangle[row][col];
            }
        }
        return triangle[0][0];
        */

        /*
            // recursion with memoization
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        return recur(0, 0, dp, triangle);
        */
    }

    /*
    int recur(int row, int col, vector<vector<int>>& dp, const vector<vector<int>>& triangle) {
        if (col < 0 || col >= triangle[row].size()) {
            return INT_MAX;
        }
        if (row == triangle.size() - 1) {
            return triangle[row][col];
        }
        if (dp[row][col] != INT_MAX) {
            return dp[row][col];
        }

        int up = recur(row+1, col, dp, triangle);
        int up_right = recur(row+1, col+1, dp, triangle);
        dp[row][col] = min(up, up_right) + triangle[row][col];
        return dp[row][col];
    }
    */
};
