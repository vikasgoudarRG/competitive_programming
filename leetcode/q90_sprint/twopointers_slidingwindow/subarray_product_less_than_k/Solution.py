from typing import List
import math

class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        # my solution is approach 1 only
        # return self.my_solution(nums, k)
        return self.prefix_log(nums, k)


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

    # Prefix Sum
    # Time Complexity O(n * logn)
    # Space Complexity O(n)
    # Usefull when cases exists where product of subarrays cause overflow
    # thus we convert problem from products to sum of logs
    # a*b*c = k becomes log(a) + log(b) + log(c) = log(k)
    # a setback is that log gives float, whose operations aren't always accurate and need buffer
    def prefix_log(self, nums: List[int], k: int) -> int:
        if (k < 1):
            return 0

        n: int = len(nums)
        log_k: float = math.log(k)
        prefix_sum = 0

        low: int = 0
        high: int = 0
        ans: int = 0

        while high < n:
            prefix_sum += math.log(nums[high])

            while (low <= high and prefix_sum >= log_k - 1e-9):
                prefix_sum -= math.log(nums[low])
                low += 1
            
            ans += (high - low + 1)
            high += 1
        
        return ans
            





