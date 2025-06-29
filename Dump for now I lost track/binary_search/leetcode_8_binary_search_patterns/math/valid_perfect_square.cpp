// https://leetcode.com/problems/valid-perfect-square/?envType=study-plan-v2&envId=binary-search

class Solution {
public:
    bool isPerfectSquare(int num) {
            // newton's method
        if (num == 1) return true;
        long long x = num / 2;

        while (x*x > num) {
            x = (x + num/x) / 2;
        }

        return (x*x == num);
        
        /*
        int l = 1;
        int r = num / 2;

        if (num < 2) {
            return true;
        }
        while (l <= r) {
            int m = l + (r - l) / 2;
            long long square = (long long) m*m;
            if (square == num) {
                return true;
            }
            else if (square > num) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return false;
        */
    }
};
