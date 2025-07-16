public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        // Time Complexity O(n)
        // Space Complexity O(n)
        Dictionary<int, int> dict = new Dictionary<int, int>();
        int[] ans = {-1, -1};

        for (int i = 0; i < nums.Length; ++i) {
            int complement = target - nums[i];
            if (dict.ContainsKey(complement)) {
                ans[0] = dict[complement];
                ans[1] = i;
                break;
            }

            else {
                dict[nums[i]] = i;
            }
        }

        return ans;
    }
}