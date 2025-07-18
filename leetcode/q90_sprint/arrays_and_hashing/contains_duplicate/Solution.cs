public class Solution {
    public bool ContainsDuplicate(int[] nums) {
        // return BruteForce(nums);
        return Sorting(nums);
    } 

    // Brute Force
    // Time Complexity O(n*2)
    // Space Complexity O(1)
    public bool BruteForce(int[] nums) {
        for (int i = 0; i < nums.Length; ++i) {
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
    // Space Complexity O(1) if in place, else O(n)
    public bool Sorting(int[] nums) {
        Array.Sort(nums);
        for (int i = 1; i < nums.Length; ++i) {
            if (nums[i] == nums[i-1]) {
                return true;
            }
        }
        return false;
    }

    // HashSet
    // Time Complexity O(n)
    // Space Complexity O(n)
    public bool Hashing(int[] nums) {
        HashSet<int> hashSet = new HashSet<int>();
        foreach(int num in nums) {
            if (hashSet.Contains(num)) {
                return true;
            }
            hashSet.Add(num);
        }

        return false;
    }
}