// https://leetcode.com/problems/kth-missing-positive-number/submissions/1656964334/?envType=study-plan-v2&envId=binary-search

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        /*
            // O(N)
        for (int i : arr) {
            if (i <= k) {
                ++k;
            }
            else {
                break;
            }
        }
        return k;
        */
            // O(logN)
        int l = 0;
        int r = arr.size();

        while (l < r) {
            int m = l + (r - l) / 2;
            int miss = (arr[m] - 1 - m);

            if (miss < k) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        return l + k;

    }
};
