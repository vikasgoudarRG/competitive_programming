// https://leetcode.com/problems/minimum-falling-path-sum/submissions/1646843684/?source=submission-noac

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
            // 1d array
        int n = matrix.size();
        vector<int> dp(n, 0);

        for (int row = n-1; row >= 0; --row) {
            vector<int> temp_dp(n, 0);
            for (int col = 0; col < n; ++col) {
                int left = col-1 >= 0 ? dp[col-1] : INT_MAX;
                int right = col+1 < n ? dp[col+1] : INT_MAX;

                temp_dp[col] = min(dp[col], min(left, right)) + matrix[row][col];
            }
            dp = temp_dp;
        }   

        int min_ = INT_MAX;
        for (int col = 0; col < n; ++col) {
            min_ = min(min_, dp[col]);
        }
        return min_;

        /*
            // 2d array 
        int n = matrix.size();
        vector<vector<int>> dp(n+1, vector<int>(n, 0));

        for (int level = n-1; level >= 0; --level) {
            for (int col = 0; col < n; ++col) {
                int down = dp[level+1][col];
                int left = col-1 >= 0 ? dp[level+1][col-1] : INT_MAX;
                int right = col+1 < n ? dp[level+1][col+1] : INT_MAX;
                
                dp[level][col] = min(down, min(left, right)) + matrix[level][col];
            }
         }
        
        int min_ = INT_MAX;
        for (int col = 0; col < n; ++col) {
            min_ = min(dp[0][col], min_);
        }
        return min_;
        */

        /*
            // recursion with memoization
        int n = matrix.size();
        vector<vector<int>> dp(n, vector(n, INT_MAX));
        int min_ = INT_MAX;
        for (int i = 0; i < matrix.size(); ++i) {
            min_ = min(min_, recur(i, 0, dp, matrix));
        }
        return min_;
        */
    }
    
    /*
    int recur(int index, int level, vector<vector<int>>& dp, const vector<vector<int>>& matrix) {
        if (level >= matrix.size()) return 0;
        if (index < 0 || index >= matrix.size()) return INT_MAX;
        if (dp[level][index] != INT_MAX) return dp[level][index];
        
        dp[level][index] = min(recur(index, level+1, dp, matrix), min(recur(index-1, level+1, dp, matrix), recur(index+1, level+1, dp, matrix))) + matrix[level][index];
        return dp[level][index];
    }
    */
};
