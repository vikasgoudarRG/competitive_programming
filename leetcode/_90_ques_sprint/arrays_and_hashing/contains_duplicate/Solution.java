package _90_ques_sprint.arrays_and_hashing.contains_duplicate;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution {
    public boolean containsDuplicate(int[] nums) {
        // return mySolution(nums);
        // return bruteForce(nums);
        // return sorting(nums);
        return hashing(nums);
    }

    // HashSet
    // Time Complexity O(n)
    // Space Complexity O(n)
    public boolean mySolution(int[] nums) {
        Set<Integer> seen = new HashSet<>();
        for (int num: nums) {
            if (seen.contains(num)) {
                return true;
            }
            seen.add(num);
        }

        return false;
    }

    // Brute Force
    // Time Complexity O(n*n)
    // Space Complexity O(1)
    public boolean bruteForce(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }

        return false;
    }

    // Sorting
    // Time Complexity O(n * logn)
    // Space Complexity O(1) if in place, O(n) if copying
    public boolean sorting(int[] nums) {
        Arrays.sort(nums);
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i-1]) {
                return true;
            }
        }
        return false;
    }

    // Hashing
    // Time Complexity O(n)
    // Space Complexity O(n)
    public boolean hashing(int[] nums) {
        Set<Integer> hashSet = new HashSet<>();
        for (int num: nums) {
            if (hashSet.contains(num)) {
                return true;
            }
            hashSet.add(num);
        }

        return false;
    }
}

