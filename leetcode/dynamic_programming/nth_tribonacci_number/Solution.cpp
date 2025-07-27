class Solution {
public:
    int tribonacci(int n) {
        return bottom_up(n);
    }

    // DP Bottom Up
    // Time Complexity O(n)
    // Space Complexity O(1)
    int bottom_up(int n) {
        if (n <= 1) return n;
        if (n == 2) return 1;

        int prev_3 = 0;
        int prev_2 = 1;
        int prev_1 = 1;

        for (int i = 3; i <= n; ++i) {
            int temp = prev_1;
            prev_1 = prev_1 + prev_2 + prev_3;
            prev_3 = prev_2;
            prev_2 = temp;
        }

        return prev_1;
    }
}