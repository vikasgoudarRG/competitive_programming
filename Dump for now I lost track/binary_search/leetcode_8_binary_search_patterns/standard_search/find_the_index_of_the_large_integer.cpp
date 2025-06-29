// https://leetcode.com/problems/find-the-index-of-the-large-integer/submissions/1656490873/?envType=study-plan-v2&envId=binary-search

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int l = 0;
        int r = reader.length() - 1;

        while (l < r) {
            int mid_left = l + (r - l) / 2;
            int mid_right = r - (r - l) / 2;
            
            int response = reader.compareSub(l, mid_left, mid_right, r);
            if (response == 0) {
                return mid_left;
            }
            else if (response == 1) {
                r = mid_left;
            }
            else {
                l = mid_right;
            }
        }
        return l;
    }
};
