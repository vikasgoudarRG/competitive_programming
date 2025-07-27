class Solution {
public:
    int rob(vector<int>& nums) {
        // return bottom_up(nums);
        vector<int> dp(nums.size(), -1);
        return top_bottom(nums, dp, nums.size() - 1);
    }

    // DP Bottom Up
    // Time Complexity O(n)
    // Space Complexity O(1)
    int bottom_up(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int prev_2 = nums[0];
        int prev_1 = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            int temp = prev_1;
            prev_1 = max(prev_1, prev_2 + nums[i]);
            prev_2 = temp;
        }
        return prev_1;
    }

    // DP Top Bottom
    // Time Complexity O(n)
    // Space Complexity O(n)
    int top_bottom(vector<int>& nums, vector<int>& dp, int n) {
        if (n == 0) return nums[0];
        if (n == 1) return max(nums[0], nums[1]);

        if (dp[n] != -1) return dp[n];

        dp[n] = max(
            top_bottom(nums, dp, n - 1),
            nums[n] + top_bottom(nums, dp, n - 2)
        );
        return dp[n];
    }
};
