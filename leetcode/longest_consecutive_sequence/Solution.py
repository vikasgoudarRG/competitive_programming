from typing import List, Set

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # return self.sorting(nums)
        return self.hashing(nums)
    
    # Sorting
    # Time Complexity O(n * logn)
    # Space Complexity O(1)
    def sorting(self, nums: List[int]) -> int:
        if (not nums):
            return 0

        nums.sort()
        
        n: int = len(nums)
        temp: int = 1
        longest: int = 1

        for i in range(1, n):
            if (nums[i-1] != nums[i]):
                if (nums[i-1] + 1 == nums[i]):
                    temp += 1
                else:
                    longest = max(longest, temp)
                    temp = 1
            
        return max(temp, longest)

    # HashSet
    # Time Complexity O(n)
    # Space Complexity O(n)
    def hashing(self, nums: List[int]) -> int:
        hash_set: Set[int] = set(nums)
        longest: int = 0

        for num in hash_set:
            if num - 1 not in hash_set:
                curr_longest = 1
                curr_num: int = num
                while curr_num + 1 in hash_set:
                    curr_longest += 1
                    curr_num += 1
                longest = max(longest, curr_longest)

        return longest
            