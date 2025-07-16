from typing import List

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # Time Complexity O(n)
        # Space Complexity O(1)

        low: int = 0
        high: int = len(numbers) - 1
        ans: List[int] = [-1, -1]

        while (low < high):
            sum: int = numbers[low] + numbers[high]
            if (sum == target):
                ans[0] = low + 1
                ans[1] = high + 1
                break
            elif (sum < target):
                low += 1
            else:
                high -= 1
        
        return ans