from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        return self.two_pointers(height)
    
    # Two Pointers
    # Time Complexity O(n)
    # Space Complexity O(1)
    def two_pointers(self, height: List[int]) -> int:
        left: int = 0
        right: int = len(height) - 1

        ans: int = 0
        while (left < right):
            water: int = (right - left) * min(height[right], height[left])
            ans = max(ans, water)

            if (height[left] < height[right]):
                left += 1
            else:
                right -= 1
            
        return ans