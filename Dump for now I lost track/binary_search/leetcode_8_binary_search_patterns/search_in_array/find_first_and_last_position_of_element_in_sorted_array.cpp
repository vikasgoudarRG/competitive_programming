// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/editorial/?envType=study-plan-v2&envId=binary-search

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        // first occurence
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
        if (left == nums.size()) {
            return {-1, -1};
        }
        else if (nums[left] != target){
            return {-1, -1};
        }
        else {
            ans[0] = left;
        }

        // last occurence
        right = nums.size();
        while (left < right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] <= target) {
                left = middle + 1;
            }
            else {
                right = middle;
            }
        }

        ans[1] = left - 1;

        return ans;
    }
};
