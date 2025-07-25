class Solution {
public:
    // Time Complexity O*logn)
    // Space Complexity O(n)
    bool isUgly(int n) {
        if (n <= 0) return false;

        // keep dividing by 2
        while ((n & 1) == 0) {
            n >>= 1;
        } 

        // keep keeping by 3
        while (n % 3 == 0) {
            n = n / 3;
        }

        // keep dividing by 5
        while (n % 5 == 0) {
            n = n / 5;
        }
        return n == 1;
    }

}