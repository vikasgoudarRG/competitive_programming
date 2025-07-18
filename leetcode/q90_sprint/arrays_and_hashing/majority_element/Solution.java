package q90_sprint.arrays_and_hashing.majority_element;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int majorityElement(int[] nums) {
        // return hashing(nums);
        // return sorting(nums);
        return boyer_moore_voting(nums);
    }

    // HashMap
    // Time Complexity O(n)
    // Space Complexity O(n) 
    public int hashing(int[] nums) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int num: nums) {
            count.put(num, count.getOrDefault(num, 0) + 1);
        }

        for (Map.Entry<Integer, Integer> entry: count.entrySet()) {
            if (entry.getValue() > nums.length / 2) return entry.getKey();
        }

        return -1;
    }

    // Sorting
    // Time Complexity O(n)
    // Space Complexity O(n)
    public int sorting(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length / 2];
    }

    public int boyer_moore_voting(int[] nums) {
        int candidate = 0;
        int count = 0;
        for (int num : nums) {
            if (count == 0) candidate = num;
            count += (candidate == num) ? 1 : -1;
        }

        return candidate;
    }
}
