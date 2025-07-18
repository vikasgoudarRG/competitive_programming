public class Solution {
    public int LongestConsecutive(int[] nums) 
    {
        // return sorting(nums);
        return hashing(nums);
    }
    
    // Sorting 
    // Time Complexity O(n * logn)
    // Space Complexity O(n)
    public int sorting(int[] nums) 
    {
        if (nums.Length == 0) 
        {
            return 0;
        }

        Array.Sort(nums);
        int n = nums.Length;

        int longest = 1;
        int curr_longest = 1;
        for (int i = 1; i < n; ++i) 
        {
            if (nums[i] != nums[i-1])
            {
                if (nums[i] == nums[i - 1] + 1)
                {
                    curr_longest++;
                }
                else
                {
                    longest = Math.Max(curr_longest, longest);
                    curr_longest = 1;
                }
            }
        }
        return Math.Max(longest, curr_longest);
    }

    // HashSet
    // Time Complexity O(n)
    // Space Complexity O(n)
    public int hashing(int[] nums)
    {
        int n = nums.Length;
        if (n == 0) return 0;

        int longest = 0;
        HashSet<int> set = new HashSet<int>(nums);

        foreach (int e in set)
        {
            if (!set.Contains(e-1)) 
            {
                int temp_e = e;
                int temp_longest = 1;
                while (set.Contains(temp_e + 1))
                {
                    temp_e++;
                    temp_longest++;
                } 
                longest = Math.Max(longest, temp_longest);
            }
        }

        return longest;
    }
}