# https://leetcode.com/problems/container-with-most-water/description/

from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        # 2 pointers
        # Time Complexity O(n)
        # Space Complexity O(1)

        max_area: int = 0
        left: int = 0
        right: int = len(height) - 1

        while (left < right):
            width: int = right - left
            area: int = width * min(height[left], height[right])

            max_area = max(max_area, area)
            if (height[left] <= height[right]):
                left += 1
            else:
                right -= 1
        return max_area