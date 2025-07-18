from typing import List, Dict

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # Time Complexity O(n)
        # Space Complexity O(n)

        ans: List[int] = [-1, -1]
        seen: Dict[int, int] = dict()

        for index, elem in enumerate(nums): 
            complement: int = target - elem
            if (complement in seen):
                ans[0] = seen[complement]
                ans[1] = index
                break

            else:
                seen[elem] = index

        return ans

