// https://leetcode.com/problems/n-th-tribonacci-number/submissions/1645694165/?envType=study-plan-v2&envId=dynamic-programming

class Solution {
public:
    int tribonacci(int n) {
        if (n <= 1) return n;
        if (n == 2) return 1;

        int a = 0, b = 1, c = 1;
        for (int i = 3; i <= n; ++i) {
            int temp = c;
            c = a + b + c;
            a = b;
            b = temp;
        }
        return c;
    }
};
