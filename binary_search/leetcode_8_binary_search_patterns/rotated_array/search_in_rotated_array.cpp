// https://leetcode.com/problems/search-in-rotated-sorted-array/editorial/?envType=study-plan-v2&envId=binary-search

class Solution {
public:
    int search(vector<int>& nums, int target) {
            // one search
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {
                return m;
            }

            if (nums[m] >= nums[l]) {
                if (nums[l] <= target && target < nums[m]) {
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
            else {
                if (nums[m] < target && target <= nums[r]) {
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
        }
        return -1;


            // finding pivot and 
           // binary search on both halves or perform one binary search with pivot to transform index
        /*
            // finding pivot
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
            // using 2 searches
        int ans = binary_search(nums, target, 0, l-1);
        if (ans != -1) {
            return ans;
        }
        else {
            return binary_search(nums, target, l, nums.size() - 1);
        }
       
            // using offset seach
        return binary_search_offset(nums, target, 0, nums.size() - 1, l);
        */
        
    }

    int binary_search(const vector<int>& nums, int target, int l, int r) {
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {
                return m;
            }
            if (nums[m] > target) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return -1;
    }

    int binary_search_offset(const vector<int>& nums, int target, int l, int r, int offset) {
        int n = nums.size();
        while (l <= r) {
            int m = l + (r - l) / 2;
            int m_real = (m + offset) % n;
            if (nums[m_real] == target) {
                return m_real;
            }
            if (nums[m_real] < target) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return -1;
    }
};
