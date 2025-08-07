// https://leetcode.com/problems/find-pivot-index/

#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        return my_prefix_sum(nums);
    }

    // My Soln
    // Prefix Sum 
    // Time Complexity O(n)
    // Space Complexity O(1)
    int my_prefix_sum(const vector<int>& nums) {
        int total = 0;
        for (int elem: nums) {
            total += elem;
        }

        int n = nums.size();
        int sum_running = 0;
        for (int i = 0; i < n; ++i) {
            if (sum_running == total - sum_running - nums[i]) return i;
            sum_running += nums[i];
        }
        return -1;
    }
};
