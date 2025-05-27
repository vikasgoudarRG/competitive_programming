// https://leetcode.com/problems/climbing-stairs/?envType=study-plan-v2&envId=dynamic-programming

class Solution {
public:
    int climbStairs(int n) {
        
            // dynamic programming approach

        int step_a = 1;
        int step_b = 1;

        for (int i = 2; i <= n; ++i) {
            int temp = step_b;
            step_b = step_b + step_a;
            step_a = temp;
        }

        return step_b;
        

        /*
            // recursion with memoization

        vector<int> memo(n+1, 0);
        return recur(0, n, memo);
        */
    }
    /*
    int recur(int i, int n, vector<int>& memo) {
        if (i > n) return 0;
        if (i == n) return 1;

        if (memo[i] > 0) {
            return memo[i];
        }
        memo[i] = recur(i+1, n, memo) + recur(i+2, n, memo);
        return memo[i];
        */
    }
};
