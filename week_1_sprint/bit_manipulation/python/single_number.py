# https://leetcode.com/problems/single-number/description/

from collections import defaultdict
from typing import List, DefaultDict

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        # List operations
        # Time Complexity O(n^2)
        # Space Complexity O(n)
        
            # create another list no_duplicates
            # if element not in no_duplicates, append it else remove it
            # at the end, only element that occurs once remains
        # return self.sol_1(nums)

        # =======================================

        # Hash Operations
        # Time Complexity O(n)
        # Space Complexity O(n)

            # create a hash table to count frequency
        # return self.sol_2(nums)

        # =======================================
        # Bit Manipulation
        # Time Complexity O(n)
        # Space Complexity O(1)

            # xor of same number twice = 0
        return self.sol_3(nums)

    
    def sol_1(self, nums: List[int]) -> int:
        no_duplicates: List[int] = []
        for i in nums:
            if i not in no_duplicates:
                no_duplicates.append(i)
            else:
                no_duplicates.remove(i)
        return no_duplicates.pop()

    def sol_2(self, nums: List[int]) -> int:
        hash: DefaultDict[int, int] = defaultdict(int)
        for i in nums:
            hash[i] += 1
        
        for i in hash:
            if hash[i] == 1:
                return i
        return 0

    def sol_3(self, nums: List[int]) -> int:
        x: int = 0
        for i in nums:
            x ^= i
        
        return x