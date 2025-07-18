class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // return prefix(nums);
        return prefix_2(nums);
    }

    // Product Prefix
    // Time Complexity O(n)
    // Space Complexity O(n)
    vector<int> prefix(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_left(n, 1);
        vector<int> prefix_right(n, 1);

        for (int i = 1; i < n; ++i) {
            prefix_left[i] = prefix_left[i-1] * nums[i-1];
        }

        for (int i = n - 2; i > -1; --i) {
            prefix_right[i] = prefix_right[i + 1] * nums[i + 1];
        }

        vector<int> ans(n, 1);
        for (int i = 0; i < n; ++i) {
            ans[i] = prefix_left[i] * prefix_right[i];
        }

        return ans;
    }

    // Product Prefix without L R prefix arrays
    // Time Complexity O(n)
    // Space Complexity O(1)
    vector<int> prefix_2(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        for (int i = 1; i < n; ++i) {
            ans[i] = ans[i-1] * nums[i-1];
        }

        int prod_r = 1;
        for (int i = n - 1; i > -1; --i) {
            ans[i] *= prod_r;
            prod_r *= nums[i];
        }

        return ans;
    }
}