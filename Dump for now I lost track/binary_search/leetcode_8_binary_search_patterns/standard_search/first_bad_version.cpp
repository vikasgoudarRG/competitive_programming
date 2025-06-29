// https://leetcode.com/problems/first-bad-version/submissions/1656438118/?envType=study-plan-v2&envId=binary-search

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l = 1;
        long long r = (long long)n + 1;
        while (l < r) {
            long long m = l + (r - l) / 2;
            bool response = isBadVersion(m);
            if (!response) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        if (l - 1 == n) {
            return - 1;
        }
        else {
            return l;
        }
       
    }
};
