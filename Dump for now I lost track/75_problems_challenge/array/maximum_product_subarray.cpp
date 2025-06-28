// https://leetcode.com/problems/maximum-product-subarray/submissions/1642924073/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            int temp = max(nums[i], max(nums[i]*max_so_far, nums[i]*min_so_far));
            min_so_far = min(nums[i], min(nums[i]*max_so_far, nums[i]*min_so_far));

            max_so_far = temp;

            result = max(max_so_far, result);
        }
        return result;
    }
};
