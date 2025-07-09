# https://leetcode.com/problems/missing-number/description/

from typing import List

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        # Sorting
        # Time Complexity O(n * logn)
        # Space Complexity O(1) or O(n) if modifying nums is forbidden

        ## return self.sol_1(nums)

        # =====================================

        # Hash Set
        # Time Complexity O(n)
        # Space Complexity O(n)

        ## return self.sol_2(nums)     

        # =====================================

        # Bit manipulation
        # Time Complexity O(n)
        # Space Complexity O(1)

        ## return self.sol_3(nums)

        # =====================================

        # Sum Formula
        # Time Complexity O(n)
        # Space Complexity O(1)

        return self.sol_4(nums)
        
    def sol_1(self, nums: List[int]) -> int:
        nums.sort()
        for i in range(len(nums)):
            if (i != nums[i]):
                return i
        return len(nums)

    def sol_2(self, nums: List[int]) -> int:
        hash_set = set(nums)
        for i in range(len(nums) + 1):
            if i not in hash_set:
                return i
        return -1

    def sol_3(self, nums: List[int]) -> int:
        missing: int = len(nums)
        for i, j in enumerate(nums):
            missing = missing ^ i ^ j
        
        return missing

    def sol_4(self, nums: List[int]) -> int:
        req_sum: int = len(nums) * (len(nums) + 1) // 2
        actual_sum: int = sum(nums)
        return req_sum - actual_sum