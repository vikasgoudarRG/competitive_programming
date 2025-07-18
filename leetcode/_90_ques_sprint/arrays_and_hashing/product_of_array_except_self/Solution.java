package _90_ques_sprint.arrays_and_hashing.product_of_array_except_self;

class Solution {
    public int[] productExceptSelf(int[] nums) {
        // return prefix(nums);
        return prefix_2(nums);
    }

    // Product Prefix
    // Time Complexity O(n)
    // Space Complexity O(n)
    public int[] prefix(int[] nums) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        int[] ans = new int[n];

        left[0] = 1;
        right[n-1] = 1;

        for (int i = 1; i < n; ++i) {
            left[i] = left[i - 1] * nums[i-1];
        }

        for (int i = n - 2; i > -1; --i) {
            right[i] = right[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; ++i) {
            ans[i] = left[i] * right[i];
        }

        return ans;
    }

    // Product Prefix without L and R prefix
    // Time Complexity O(n)
    // Space Complexity O(1)
    public int[] prefix_2(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];

        ans[0] = 1;
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