import collections
import heapq
from typing import List, Tuple


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
       return self.heap(nums, k)

    # Heap
    # Time Complexity O(n*)
    def heap(self, nums: List[int], k: int) -> List[int]:
        # O(n)
        count: collections.Counter[int] = collections.Counter(nums)

        heap: List[Tuple[int, int]] = []

        # O(n * logk)
        for num, freq in count.items():
            heapq.heappush(heap, (freq, num))
            if (len(heap) > k):
                heapq.heappop(heap)
            
        return [num for _, num in heap]
