// https://leetcode.com/problems/fibonacci-number/?envType=study-plan-v2&envId=dynamic-programming

class Solution {
public:
    int fib(int n) {
            // matrix exponentiation
        if (n == 0) return 0;
        vector<vector<long long>> a = { { 1, 1 }, { 1, 0 } };
        vector<vector<long long>> res = bin_pow(a, n - 1);
        return res[0][0];
        /*
            // dynamic programming
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        int a = 0;
        int b = 1;

        for (int i = 2; i <= n; ++i) {
            int temp = b;
            b = a + b;
            a = temp;
        }

        return b;
        */

        /*
            // recursion with memoization
        vector<int> memo(n + 1, 0);
        return recur(0, n, memo);
        */
    }
    /*
    int recur(int i, int n, vector<int>& memo) {
        if (i > n) return 0;
        if (i == n) return 0;
        if (i == n - 1) return 1;

        if (memo[i] > 0) return memo[i];
        memo[i] = recur(i+1, n, memo) + recur(i+2, n, memo);
        return memo[i];
    }
    */
    vector<vector<long long>> bin_pow(vector<vector<long long>> a, int n) {
        vector<vector<long long>> ans = { { 1, 0 }, { 0, 1 } };
        while (n > 0) {
            if (n & 1) {
                ans = mult(ans, a);
            }
            a = mult(a, a);
            n >>= 1;
        }
        return ans;
    }

    vector<vector<long long>> mult(vector<vector<long long>>& a, vector<vector<long long>>& b) {
        vector<vector<long long>> result(a.size(), vector<long long>(b[0].size(), 0));
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < b.size(); ++j) {
                for (int k = 0; k < a[0].size(); ++k) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return result;
    }
};
