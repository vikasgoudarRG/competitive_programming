package longest_consecutive_sequence;

import java.util.Arrays;

class Solution {
    public int longestConsecutive(int[] nums) {
        return sorting(nums);
    }

    public int sorting(int[] nums) {
        if (nums.length == 0) return 0;

        int n = nums.length; 
        Arrays.sort(nums);

        int longest = 1;
        int current_longest = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[i-1]) {
                if (nums[i] == nums[i-1] + 1) {
                    current_longest++;
                }
                else {
                    longest = Math.max(longest, current_longest);
                    current_longest = 1;
                }
            }
        }
        return Math.max(longest, current_longest);
    }
}