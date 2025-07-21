from typing import List

class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        return self.my_solution(nums, k)


    # Sliding Window
    # Time Complexity O(n)
    # Space Complexity O(1)
    def my_solution(self, nums: List[int], k: int) -> int:
        low: int = 0
        high: int = 0

        n: int = len(nums)

        curr_prod: int = 1
        ans: int = 0

        while (high < n):
            num: int = nums[high]

            curr_prod *= num

            while (low <= high and curr_prod >= k):
                num: int = nums[low]
                curr_prod = curr_prod // num
                low += 1
            
            ans += (high - low + 1)

            high += 1
        
        return ans


