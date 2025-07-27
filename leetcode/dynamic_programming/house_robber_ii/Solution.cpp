class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return 0;
        if (n == 1) return nums[0];

        return max(
            bottom_up(nums, 0, n - 2),
            bottom_up(nums, 1, n - 1)
        );
    }

    // DP Bottom Up
    // Time Complexity O(n)
    // Space Complexity O(1)
    int bottom_up(vector<int>& nums, int low, int high) {
        int prev_2 = 0;
        int prev_1 = 0;

        for (int i = low; i <= high; ++i) {
            int temp = prev_1;
            prev_1 = max(prev_1, nums[i] + prev_2);
            prev_2 = temp;
        }

        return prev_1;
    }
}