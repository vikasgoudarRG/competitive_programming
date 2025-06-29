// https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/submissions/1656477878/?envType=study-plan-v2&envId=binary-search

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int l = 0;
        int r = 1;

        while (reader.get(r) < target) {
            l = r + 1;
            r <<= 1;
        }

        while (l <= r) {
            int m = l + (r - l) / 2;
            int response = reader.get(m);
            if (response == target) {
                return m;
            }
            else if (response > target) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return -1;
    }
};
