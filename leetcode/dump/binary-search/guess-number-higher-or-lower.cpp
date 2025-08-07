// https://leetcode.com/problems/guess-number-higher-or-lower/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        return my_binary_search(n);
    }

    // My Soln
    // Time Complexity O(log n)
    // Space Complexity O(1)
    int my_binary_search(int n) {
        int low = 1;
        int high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int response = guess(mid);

            if (response == 0) return mid;
            if (response > 0) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};
