// https://leetcode.com/problems/search-insert-position/description/?envType=study-plan-v2&envId=binary-search

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();

        while (left < right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] >= target) {
                right = middle;
            }
            else {
                left = middle + 1;
            }
        }
        return left;
    }
};
