package q90_sprint.arrays_and_hashing.longest_consecutive_sequence;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution {    
    public int longestConsecutive(int[] nums) {
        // return sorting(nums);
        return hashing(nums);
    }

    // Sorting
    // Time Complexity O(n * logn)
    // Space Complexity O(1)
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

    // HashSet
    // Time Complexity O(n)
    // Space Compelxity O(n)
    public int hashing(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;

        Set<Integer> set = new HashSet<>();
        for (int e: nums) set.add(e);
        int longest = 1;
        for (int e: set) {
            if (!set.contains(e - 1)) {
                int e_copy = e;
                int temp_longest = 1;
                while (set.contains(e_copy + 1)) {
                    e_copy++;
                    temp_longest++;
                }
                longest = Math.max(temp_longest, longest);
            }
        }
        return longest;
        
    }
}