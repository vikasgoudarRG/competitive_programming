// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/?envType=study-plan-v2&envId=binary-search

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        /*
        int last_positive = grid[0].size() - 1;
        int total_negatives = 0;
        for (int row = 0; row < grid.size(); ++row) {
            while (last_positive >= 0 &&grid[row][last_positive] < 0) {
                last_positive--;
            }
            total_negatives += grid[0].size() - last_positive - 1;
        }
        return total_negatives;
        */
        
        int right = grid[0].size();
        int left = 0;
        int total_negatives = 0;
        for (int row = 0; row < grid.size(); ++row) {
            left = 0;
            while (left < right) {
                int middle = left + (right - left) / 2;
                if (grid[row][middle] >= 0) {
                    left = middle + 1;
                }
                else {
                    right = middle;
                }
            }
            total_negatives += grid[0].size() - right;
        }
        return total_negatives;
        
    }
};
