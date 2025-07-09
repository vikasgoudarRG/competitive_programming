# https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

from typing import List

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # Two Pointers
        # Time Complexity O(n)
        # Space Complexity O(1)
        i: int = 0
        j: int = len(numbers) - 1
        ans: List[int] = [-1, -1]

        while i < j:
            sum: int = numbers[i] + numbers[j]
            if (sum > target):
                j -= 1
            elif (sum < target):
                i += 1
            else:
                ans[0] = i + 1
                ans[1] = j + 1
                break

        return ans
            