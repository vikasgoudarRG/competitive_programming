// https://leetcode.com/problems/guess-number-higher-or-lower/editorial/?envType=study-plan-v2&envId=binary-search

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
        int l = 1;
        int r = n;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int res = guess(m);
            if (res == 0) {
                return m;
            }
            else if (res == 1) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return -1;
    }
};
