class Solution {
public:
    int climbStairs(int n) {
        // return bottom_up(n);
        vector<int> dp(n + 1, -1);
        return top_bottom(n, dp);
    }

    // DP Bottom-Up
    // Time Complexity O(n)
    // Space Complexity O(1)
    int bottom_up(int n) {
        if (n <= 2) return n;
        int a = 1;
        int b = 2;
        for (int i = 3; i <= n; ++i) {
            int temp = b;
            b = b + a;
            a = temp;
        }

        return b;
    }

    int top_bottom(int n, vector<int>& dp) {
        if (n <= 2) {
            return n;
        }
        if (dp[n] != -1) return dp[n];

        dp[n] = top_bottom(n - 1, dp) + top_bottom(n - 2, dp);

        return dp[n];
    }
}