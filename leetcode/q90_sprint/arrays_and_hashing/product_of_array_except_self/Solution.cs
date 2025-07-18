public class Solution {
    public int[] ProductExceptSelf(int[] nums) {
        // return prefix(nums);
        return prefix_2(nums);
    }

    // Product prefix
    // Time Complexity O(n)
    // Space Complexity O(n)
    public int[] prefix(int[] nums) {
        int n = nums.Length;
        int[] l = new int[n];
        int[] r = new int[n];
        int[] ans = new int[n];

        l[0] = 1;
        for (int i = 1; i < n; ++i) {
            l[i] = l[i-1] * nums[i-1];
        }

        r[n-1] = 1;
        for (int i = n - 2; i > -1; --i) {
            r[i] = r[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; ++i) {
            ans[i] = l[i] * r[i];
        }

        return ans;
    }


    // Product Prefix without L R prefix
    // Time Compelxity O(n)
    // Space Complexity O(1)
    public int[] prefix_2(int[] nums)
    {
        int n = nums.Length;
        int[] ans = new int[n];

        ans[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            ans[i] = ans[i-1] * nums[i-1];
        }

        int prod_r = 1;
        for (int i = n - 1; i > -1; --i)
        {
            ans[i] *= prod_r;
            prod_r *= nums[i];
        }

        return ans;
    }
}