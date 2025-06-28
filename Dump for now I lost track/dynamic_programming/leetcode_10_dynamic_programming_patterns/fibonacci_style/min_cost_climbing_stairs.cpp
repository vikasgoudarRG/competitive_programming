// https://leetcode.com/problems/min-cost-climbing-stairs/?envType=study-plan-v2&envId=dynamic-programming

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        int cost_a = 0;
        int cost_b = cost[0];

        for (int i = 1; i < n; ++i) {
            int temp = cost_b;
            cost_b = min(cost_b, cost_a) + cost[i];
            cost_a = temp;
        }
        return min(cost_a, cost_b);
        

        /*
            // bottom up (tabulation)
        vector<int> dp(cost.size() + 1, 0);
        for (int i = 2; i < dp.size(); ++i) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        return dp[dp.size() - 1];
        */

        /*
            // to down (recursion + memoization)
        vector<int> memo(cost.size() + 1, -1);
        return recur(cost.size(), cost, memo);
        */

    }

    /*
    int recur(int n, const vector<int>& cost, vector<int>& memo) {
        if (n <= 1) return 0;

        if (memo[n] != -1) return memo[n];

        memo[n] = min(recur(n-1, cost, memo) + cost[n-1], recur(n-2, cost, memo) + cost[n-2]);
        return memo[n];
    }
    */
    
};
