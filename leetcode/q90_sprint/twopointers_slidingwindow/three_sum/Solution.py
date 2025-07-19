from typing import List, Set


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # return self.two_pointers(nums)
        return self.hashing(nums)
    
    # Two Pointers
    # Time Complexity O(n^2)
    # Space Complexity O(1)
    def two_pointers(self, nums: List[int]) -> List[List[int]]:
        n: int = len(nums)

        nums.sort()
        ans: List[List[int]] = list()

        for i in range(n):
            if (nums[i] > 0):
                break
            
            if (i == 0 or nums[i] != nums[i-1]):
                low: int = i + 1
                high: int = n - 1

                while (low < high):
                    if (nums[low] + nums[high] + nums[i] == 0):
                        ans.append([nums[i], nums[low], nums[high]])
                        low += 1
                        high -= 1
                        while (low < high and nums[low] == nums[low-1]):
                            low += 1
                    elif (nums[low] + nums[high] + nums[i] < 0):
                        low += 1
                    else:
                        high -= 1
        return ans

    # HashMap
    # Time Complexity O (n^2)
    # Space Complexity O(n)
    def hashing(self, nums: List[int]) -> List[List[int]]:
        n: int = len(nums)
        nums.sort()
        ans: List[List[int]] = []

        for i in range(n):
            if (nums[i] > 0):
                break
            if (i == 0 or nums[i] != nums[i-1]):
                seen: Set[int] = set()
                j: int = i + 1

                while (j < n):
                    complement: int = -nums[i] - nums[j]
                    if (complement in seen):
                        ans.append([nums[i], nums[j], complement])
                        while (j + 1 < n and nums[j] == nums[j+1]):
                            j += 1
                    seen.add(nums[j])
                    j += 1
        return ans


