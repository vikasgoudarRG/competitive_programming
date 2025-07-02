# https://leetcode.com/problems/contains-duplicate/

from typing import List, Set

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        # Linear Search 
        # Time Complexity O(n^2)
        """
        n: int = len(nums)

        for i in range(0, n):
            for j in range(0, i):
                if (nums[i] == nums[j]):
                    return True

        return False
        """

        # Sort and Search
        # Time Complexity O(n*log(n))
        """
        nums.sort()
        n: int = len(nums)

        for i in range(1, n):
            if (nums[i] == nums[i-1]):
                return True

        return False
        """

        # Set 
        # Time Complexity O(n)
        """
        By default in python Set and Dict are Hash based, not tree based
        Note
        This method isn't always faster than sort and search in practice, since hashing involves a lot of backend operations
        like hashing and collision control
        """

        distinct: Set[int] = set()
        for num in nums:
            if (num in distinct):
                return True
            distinct.add(num)
        return False