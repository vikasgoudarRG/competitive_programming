package q90_sprint.arrays_and_hashing.two_sum;

import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        // Time Complexity O(n)
        // Space Complexity O(n)
        Map<Integer, Integer> hash_map = new HashMap<>();
        int[] ans = {-1, -1};

        for (int i = 0; i < nums.length; ++i) {
            int complement = target - nums[i];
            if (hash_map.containsKey(complement)) {
                ans[0] = hash_map.get(complement);
                ans[1] = i;
                break;
            }
            else {
                hash_map.put(nums[i], i);
            }
        }    

        return ans;
    }
}