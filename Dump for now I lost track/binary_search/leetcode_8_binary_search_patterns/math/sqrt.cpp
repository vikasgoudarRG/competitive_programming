// https://leetcode.com/problems/sqrtx/?envType=study-plan-v2&envId=binary-search

class Solution {
public:
    int mySqrt(int num) {
        
            // newtons method
        if (num == 1) return true;
        long long x = num / 2;

        while (x*x > num) {
            x = (x + num/x) / 2;
        }

        return x;
        
        /*
        if (num == 1) return 1;

        int l = 1;
        int r = num / 2 + 1;

        while (l < r) {
            long long m = l + (r-l) / 2;
            long long sq = m*m;
            if (sq <= num) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        --l;
        return l;
        */
    }
};
