class Solution {
public:
    int fib(int n) {
        return dynamic_programming(n);
    }

    // DP
    // Time Complexity O(n)
    // Space Complexity O(1)
    int dynamic_programming(int n) {
        if (n <= 1) return n;

        int a = 0;
        int b = 1;
        while (--n) {
            int temp = b;
            b = a + b;
            a = temp;
        }
        return b;
    }
}