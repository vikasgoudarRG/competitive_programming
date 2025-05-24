// https://leetcode.com/problems/product-of-array-except-self/ 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre_prod(nums.size());
        vector<int> post_prod(nums.size());

        pre_prod[0] = 1;
        post_prod[nums.size() - 1] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            pre_prod[i] = nums[i - 1] * pre_prod[i - 1];
            post_prod[nums.size() - 1 - i] = nums[nums.size() - i] * post_prod[nums.size() - i];
        }

        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            ans[i] = pre_prod[i] * post_prod[i];
        }

        return ans;
    }
};
