// https://leetcode.com/problems/arranging-coins/?envType=study-plan-v2&envId=binary-search

class Solution {
public:
    int arrangeCoins(int n) {
        
            // binary search
        int l = 1;
        int r = n;

        while (l <= r) {
            long long m = l + (r - l) / 2;
            long long total = m*(m+1)/2;

            if (total == n) {
                return m;
            }
            else if (total > n) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return r;
        

            // upper bound
            /*
        int l = 1;
        long long r = (long long)n + 1;
        while (l < r) {
            long long m = l + (r - l) / 2;
            long long total = m*(m+1)/2;

            if (total > n) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        return --l;
        */
    }
};
