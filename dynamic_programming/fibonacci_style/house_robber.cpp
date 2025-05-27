// https://leetcode.com/problems/house-robber/?envType=study-plan-v2&envId=dynamic-programming

class Solution {
public:
    int rob(vector<int>& nums) {
            // top bottom space optimized
        // read top-bottom to understand

        int next_plus_one = 0;
        int next = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; --i) {
            int temp = next;
            next = max(next, nums[i] + next_plus_one);
            next_plus_one = temp;
        }
        return next;

        /*
            // top-bottom
        // for explanation read recur function, which was made for recursion + memoization method
        vector<int> dp(nums.size() + 1);
        dp[nums.size()] = 0;
        dp[nums.size() - 1] = nums[nums.size() - 1];

        for (int i = nums.size() - 2; i >= 0; --i) {
            dp[i] = max(nums[i] + dp[i+2], dp[i+1]);
        }
        return dp[0];
        */

        /*
            // bottom-up

        int included = 0;
        int not_included = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int temp_included = included;
            int temp_not_included = not_included;
            included = temp_not_included + nums[i];
            not_included = max(temp_included, temp_not_included);
        }
        return max(included, not_included);
        */

        /*
            // recursive approach
        vector<int> memo(nums.size(), -1);
        return recur(0, memo, nums);
        */
    }

    /*
    // i means that the robber has to scan from ith to end (Nth house)
    // so if memo[i] is set that means, robber has scanned from ith house to Nth hosue
    int recur(int i, vector<int>& memo, const vector<int>& nums) {
        if (i >= nums.size()) return 0;

        if (memo[i] != -1) return memo[i];

        memo[i] = max(recur(i+1, memo, nums), recur(i+2, memo, nums) + nums[i]);
        return memo[i];
    }
    */
};
