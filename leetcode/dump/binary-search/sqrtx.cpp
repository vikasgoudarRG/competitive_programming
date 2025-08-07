// https://leetcode.com/problems/sqrtx/description/

class Solution {
public:
    int mySqrt(int num) {
        // return my_binary_search(num);
        return recursion(num);
    }

    // My Soln
    // Binary Search 
    // Time Complexity O(log n)
    // Space Complexity O(1)
    int my_binary_search(int num) {
        if (num == 0) return 0;
        if (num == 1) return 1;


        int low = 2;
        int high = num / 2 + 1;

        // upper bound
        while (low < high) {
            int mid = low + (high - low) / 2;
            long long square = (long long) mid * mid;

            if (square <= num) low = mid + 1;
            else high = mid;
        }
        return --low;
    }

    // Recursion 
    // Time Complexity O(logn)
    // Space Complexity O(logn)
    int recursion(int num) {
        if (num < 2) return num;

        int left = recursion(num >> 2) << 1;
        int right = left + 1;
        return (long long) right * right > num ? left : right;
    }
};
