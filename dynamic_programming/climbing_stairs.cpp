// https://leetcode.com/problems/climbing-stairs/?envType=study-plan-v2&envId=dynamic-programming

class Solution {
public:
    int climbStairs(int n) {

            // matrix fibonacci method
        if (n == 0) return 1;
        vector<vector<long long>> A = { { 1, 1 }, { 1, 0 } };
        vector<vector<long long>> res = bin_pow(A, n - 1);
        return res[0][0] + res[0][1];


        /*
            // dynamic programming approach

        int step_a = 1;
        int step_b = 1;

        for (int i = 2; i <= n; ++i) {
            int temp = step_b;
            step_b = step_b + step_a;
            step_a = temp;
        }

        return step_b;
        */

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
        
    }
    */

    vector<vector<long long>> bin_pow(vector<vector<long long>> a, int n) {
        vector<vector<long long>> res = { { 1, 0 }, { 0, 1 }};
        while (n > 0) {
            if (n & 1) {
                res = mult(res, a);
            }
            a = mult(a, a);
            n >>= 1;
        }
        return res;
    }

    vector<vector<long long>> mult(const vector<vector<long long>>& a, const vector<vector<long long>>& b) {
        vector<vector<long long>> res(a.size(), vector<long long>(b[0].size(), 0));
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < b[0].size(); ++j) {
                for (int k = 0; k < a[0].size(); ++k) {
                    res[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return res;
    }
};
