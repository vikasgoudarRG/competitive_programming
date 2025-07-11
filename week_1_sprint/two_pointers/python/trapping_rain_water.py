# https://leetcode.com/problems/trapping-rain-water/description/

from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        # Memoization
        # Time Complexity O(n)
        # Space Complexity O(n)

        ## return self.sol_1(height)

        # ==================================

        # Stacks
        # Time Complexity O(n)
        # Space Complexity O(1)

        ## return self.sol_2(height)

        # ===================================

        # 2 pointers
        # Time Complexity O(n)
        # Space Complexity O(1)

        return self.sol_3(height)
    
    def sol_1(self, height: List[int]) -> int:
        left_max: List[int] = [0] * len(height)
        right_max: List[int] = [0] * len(height)

        left_max[0] = height[0]
        right_max[len(height) - 1] = height[len(height) - 1]

        for i in range(1, len(height)):
            left_max[i] = max(left_max[i-1], height[i])
        
        for i in range(len(height) - 2, -1, -1):
            right_max[i] = max(right_max[i+1], height[i])

        ans: int = 0
        for i in range(len(height)):
            ans += min(left_max[i], right_max[i]) - height[i]
        
        return ans

    def sol_2(self, height: List[int]) -> int:
        stack: List[int] = []
        ans: int = 0

        for i in range(len(height)):
            while (len(stack) != 0 and height[stack[-1]] < height[i]):
                top: int = stack.pop()
                if (len(stack) == 0):
                    break
                distance: int = i - stack[-1] - 1
                ans += distance * (min(height[i], height[stack[-1]]) - height[top])
            stack.append(i)

        return ans

    def sol_3(self, height: List[int]) -> int:
        left: int = 0
        right: int = len(height) - 1

        left_max: int = 0
        right_max: int = 0

        ans: int = 0

        while (left < right):
            if (height[left] < height[right]):
                left_max = max(left_max, height[left])
                ans += left_max - height[left]
                left += 1
            else:
                right_max = max(right_max, height[right])
                ans += right_max - height[right]
                right -= 1
            
        return ans
