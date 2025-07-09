# https://leetcode.com/problems/3sum/description/

from typing import List, Set, Tuple, Dict, cast

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # Two Pointers 
        # Time Complexity O(n^2)
        # Space Complexity O(1), O(n) if we cannot modify original list

        ## return self.sol_1(nums)

        # ===========================================

        # HashSet
        # Time Complexity O(n^2)
        # Space Complexity O(n)

        ## return self.sol_2(nums)

        # ===========================================

        # VooDoo magic to avoid sorting List
        # Time Complexity O(n ^ 2)
        # Space Complexity O(n)

        return self.sol_3(nums)


    
    def sol_1(self, nums: List[int]) -> List[List[int]]:
        res: List[List[int]] = []
        nums.sort()

        for i in range(len(nums)):
            if nums[i] > 0:
                break
            if i == 0 or nums[i-1] != nums[i]:
                self.sol_1_helper(i, nums, res)
        return res

    def sol_1_helper(self, i: int, nums: List[int], res: List[List[int]]) -> None:
        low: int = i + 1
        high: int = len(nums) - 1

        while (low < high):
            sum: int = nums[i] + nums[low] + nums[high]
            if sum < 0:
                low += 1
            elif sum > 0:
                high -= 1
            else:
                res.append([nums[i], nums[low], nums[high]])
                low += 1
                high -= 1
                while (nums[low] == nums[low-1] and low < high):
                    low += 1

    def sol_2(self, nums: List[int]) -> List[List[int]]:
        res: List[List[int]] = []
        nums.sort()

        for i in range(len(nums)):
            if (nums[i] > 0):
                break
            if (i == 0 or nums[i] != nums[i-1]):
                self.sol_2_helper(i, nums, res)

        return res

    def sol_2_helper(self, i: int, nums: List[int], res: List[List[int]]) -> None:
        low: int = i + 1
        seen: Set[int] = set()

        while low < len(nums):
            complement: int = -(nums[i] + nums[low])
            if complement in seen:
                res.append([nums[i], nums[low], complement])
                seen.add(nums[low])
                low += 1
                while low < len(nums) and nums[low] == nums[low - 1]:
                    low += 1
            else:
                seen.add(nums[low])
                low += 1

    def sol_3(self, nums: List[int]) -> List[List[int]]:
        res: Set[Tuple[int, int, int]] = set()
        dup: Set[int] = set()
        seen: Dict[int, int] = dict()

        for i, val1 in enumerate(nums):
            if val1 not in dup:
                dup.add(val1)
                for _, val2 in enumerate(nums[i+1:]):
                    complement: int = -(val1 + val2)
                    if complement in seen and seen[complement] == i:
                        triplet: Tuple[int, int, int] = cast(Tuple[int, int, int], tuple(sorted((val1, val2, complement))))
                        res.add(triplet)
                    seen[val2] = i
        return [list(i) for i in res]
