// https://leetcode.com/problems/single-element-in-a-sorted-array/submissions/1657024564/?envType=study-plan-v2&envId=binary-search

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            int partner = m & 1 ? m - 1 : m + 1;

            if (nums[m] == nums[partner]) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        return nums[l];
    

        /*
            // another approach
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int m = l + (r - l) / 2;
            bool right_even = (r - m) % 2 == 0;

            if (nums[m] == nums[m+1]) {
                if (right_even) {
                    l = m + 2;
                }
                else {
                    r = m - 1;
                }
            }
            else if (nums[m] == nums[m-1]) {
                if (right_even) {
                    r = m - 2;
                }
                else {
                    l = m + 1;
                }
            }
            else {
                return nums[m];
            }
        }
        return nums[l];
        */
    }
};
