// https://leetcode.com/problems/maximal-square/submissions/1647136999/?envType=study-plan-v2&envId=dynamic-programming

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
            // 1d dp
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> dp(n+1, 0);
        int max_ = 0;
        for (int i = 1; i <= matrix.size(); ++i) {
            int prev = dp[0];
            for (int j = 1; j <= matrix[0].size(); ++j) {
                if (matrix[i-1][j-1] == '1') {
                    int temp = dp[j];
                    dp[j] = min(prev, min(dp[j], dp[j-1])) + 1;
                    prev = temp;

                    max_ = max(max_, dp[j]);
                }
                else {
                    dp[j] = 0;
                }
            }
        }
        return max_*max_;
        
        /*
            // 2d dp
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        int max_ = 0;
        for (int i = 1; i <= matrix.size(); ++i) {
            for (int j = 1; j <= matrix[0].size(); ++j) {
                if (matrix[i-1][j-1] == '1'){
                    dp[i][j] = min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j])) + 1;
                    max_ = max(max_, dp[i][j]);
                }
            }
        }
        return max_ * max_;
        */

        /*
            // brute-force
        int max_ = 0;
        for (int row = 0; row < matrix.size(); ++row) {
            for (int col = 0; col < matrix[0].size(); ++col) {
                if (matrix[row][col] == '1') {
                    int length = 1;
                    bool isValid = true;
                    while (row + length < matrix.size() && col + length < matrix[0].size() && isValid) {
                        for (int row_ = row; row_ <= row + length; ++row_) {
                            if (matrix[row_][col+length] == '0') {
                                isValid = false;
                                break;
                            }
                        }
                        for (int col_ = col; col_ <= col + length; ++col_) {
                            if (matrix[row+length][col_] == '0') {
                                isValid = false;
                                break;
                            }
                        }
                        if (isValid) length++;
                    }
                    max_ = max(max_, length);
                }
            }
        }
        return max_*max_;
        */
    }
};
