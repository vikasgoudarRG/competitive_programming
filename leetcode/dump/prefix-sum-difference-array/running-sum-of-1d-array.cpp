// https://leetcode.com/problems/running-sum-of-1d-array/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        return my_prefix_sum(nums);
    }

    // Prefix Sum
    // Time Complexity O(n)
    // Space Complexity O(n)
    vector<int> my_prefix_sum(const vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_array(n, 0);

        prefix_array[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefix_array[i] = prefix_array[i-1] + nums[i];
        }
        return prefix_array;
    }
};
