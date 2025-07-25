class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // return bottom_up(cost);
        vector<int> dp(cost.size() + 1, -1);
        return top_bottom(cost, cost.size(), dp);
    }

    // DP Bottom Up
    // Time Complexity O(n)
    // Space Complexity O(1)
    int bottom_up(vector<int>& cost) {
        int n = cost.size();

        int a = 0;
        int b = 0;

        for (int i = 2; i <= n; ++i) {
            int temp = b;
            b = min(a + cost[i-2], b + cost[i-1]);
            a = temp;
        }
        return b;
    }

    // DP Top Bottom
    // Time Complexity O(n)
    // Space Complexity O(n)
    int top_bottom(vector<int>& cost, int n, vector<int>& dp) {
        if (n <= 1) return 0;

        if (dp[n] != -1) return dp[n];

        dp[n] = min( cost[n - 1] + top_bottom(cost, n - 1, dp), cost[n-2] + top_bottom(cost, n -2, dp) );
        return dp[n];
    }
}