from typing import Dict, List


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        # return self.brute_force(nums, k)
        # return self.brute_force_prefix(nums, k)
        return self.hashing(nums, k)



    # Brute Force
    # Time Complexity O(n^2)
    # Space Complexity O(1)
    def brute_force(self, nums: List[int], k: int) -> int:
        n: int = len(nums)
        ans: int = 0
        for i in range(n):
            sum: int = 0
            for j in range(i, n):
                sum += nums[j]
                if (sum == k):
                    ans += 1
        return ans

    # Brute Force Prefix Sum
    # Time Complexity O(n^2)
    # Space Complexity O(n)
    def brute_force_prefix(self, nums: List[int], k: int) -> int:
        n: int = len(nums)
        prefix_sum: List[int] = [0] * (n + 1)

        for i in range(1, n + 1):
            prefix_sum[i] = prefix_sum[i-1] + nums[i-1]
        
        ans: int = 0
        for start in range(n):
            for end in range(start, n):
                sum: int = prefix_sum[end + 1] - prefix_sum[start]
                if (sum == k):
                    ans += 1
            
        return ans

    # HashMap
    # Time Complexity O(n)
    # Space Complexity O(n)
    def hashing(self, nums: List[int], k: int) -> int:
        n: int = len(nums)
        count: int = 0
        sum_prefix_freq: Dict[int, int] = dict()
        sum_prefix_freq[0] = 1

        sum_cum: int = 0
        for index in range(n):
            sum_cum += nums[index]
            count += sum_prefix_freq.get(sum_cum - k, 0)

            sum_prefix_freq[sum_cum] = sum_prefix_freq.get(sum_cum, 0) + 1
        
        return count
    