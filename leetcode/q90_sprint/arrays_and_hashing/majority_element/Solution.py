import collections
from typing import List, Optional


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # return self.hashing(nums)
        # return self.sorting(nums)
        return self.boyer_moore_voting(nums)

    # HashMap
    # Time Complexity O(n)
    # Space Complexity O(n)
    def hashing(self, nums: List[int]) -> int:
        '''
        count: Dict[int, int] = dict()
        for num in nums:
            count[num] = count.get(num, 0) + 1
        '''
        count: collections.Counter[int] = collections.Counter(nums)
        return max(count.keys(), key=lambda k: count[k])

    # Sorting
    # Time Complexity O(n)
    # Space Complexity O(1)
    def sorting(self, nums: List[int]) -> int:
        nums.sort()
        return nums[len(nums)//2]        
    
    # Boyer Moore Voting
    # Time Complexity O(n)
    # Space Complexity O(1)
    def boyer_moore_voting(self, nums: List[int]) ->int:
        count: int = 0
        candidate: Optional[int] = None

        for n in nums:
            if count == 0:
                candidate = n
            
            count += (1 if n == candidate else -1)
        assert candidate is not None
        return candidate


