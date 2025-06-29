// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/1656360342/?envType=study-plan-v2&envId=binary-search
/*
    Array Doesn't Have Duplciate Elements
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] <= nums[r]) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        return nums[l];
    }
};
