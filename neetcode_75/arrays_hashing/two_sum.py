from typing import List, Dict

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # Brute Force
        # Time Complexity O(n^2)
        """
        n: int = len(nums)
        for i in range(n):
            for j in range(i+1, n):
                if (nums[i] + nums[j] == target):
                    return [i, j]
        
        return []
        """

        # Hashing
        # Time Complexity O(n)
        hash_map : Dict[int, int] = dict()
        for i in range(len(nums)):
            complement: int = target - nums[i]
            if complement in hash_map:
                return [i, hash_map[complement]]
            hash_map[nums[i]] = i
        
        return []