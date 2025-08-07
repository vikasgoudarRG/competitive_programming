// https://leetcode.com/problems/product-of-array-except-self/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // return my_prefix_prod(nums);
    }

    // My Soln 
    // Prefix Prod array
    // Time Complexity O(n)
    // Space Complexity O(1)
    vector<int> my_prefix_prod(const vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int run_prod_rl = 1;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] = run_prod_rl;
            run_prod_rl *= nums[i];
        }

        int run_prod_lr = 1;
        for (int i = 0; i < n; ++i) {
            ans[i] *= run_prod_lr;
            run_prod_lr *= nums[i];
        }

        return ans;
    }
};
