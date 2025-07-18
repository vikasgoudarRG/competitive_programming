public class Solution {
    public int MajorityElement(int[] nums) {
        // return hashing(nums);
        // return sorting(nums);
        return boyer_moore_voting(nums);
    }

    // HashMap
    // Time Complexity O(n)
    // Space Complexity O(1)
    public int hashing(int[] nums) {
        Dictionary<int, int> count = new Dictionary<int, int>();
        foreach (int num in nums) {
            if (!count.ContainsKey(num)) {
                count[num] = 1;
            }
            else 
            {
                count[num] += 1;
            }
        }

        foreach (KeyValuePair<int, int> pair in count) {
            if (pair.Value > nums.Length / 2) {
                return pair.Key;
            }
        }
        return -1;
    }
    
    // Sorting
    // Time Complexity O(n)
    // Space Complexity O(1)
    public int sorting(int[] nums)
    {
        Array.Sort(nums);
        return nums[nums.Length / 2];
    }

    // Boyer Moore Voting
    // Time Complexity O(n)
    // Space Complexity O(1)
    public int boyer_moore_voting(int[] nums)
    {
        int count = 0;
        int candidate = 0;

        foreach (int num in nums)
        {
            if (count == 0) candidate = num;
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
}