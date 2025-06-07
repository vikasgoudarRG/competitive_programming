// https://leetcode.com/problems/search-a-2d-matrix/editorial/?envType=study-plan-v2&envId=binary-search

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_count = matrix.size();
        int col_count = matrix[0].size();

        // finding row
        int l = 0;
        int r = row_count;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (matrix[m][0] <= target) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        --l;
        int row = l;
        if (row < 0) {
            return false;
        }

        // finding col
        l = 0;
        r = col_count - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int a = matrix[row][m];
            if (a == target) {
                return true;
            }
            if (a > target) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return false;
    }
};
