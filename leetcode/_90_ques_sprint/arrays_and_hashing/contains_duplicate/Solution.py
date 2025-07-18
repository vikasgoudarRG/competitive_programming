from typing import Set, List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        # return self.my_sol(nums)
        # return self.sol_1(nums)
        # return self.sol_2(nums)
        return self.sol_3(nums)

    # ====================================================
    ## My solution
    ## Sets
    ## Time Complexity O(n)
    def my_sol(self, nums: List[int]) -> bool:
        hash_set: Set[int] = set()

        for elem in nums:
            if (elem in hash_set):
                return True
            hash_set.add(elem)
        
        return False
    # ====================================================

    ## Sol-1
    ## Brute Force
    ## Time Complexity O(n^2) 
    ## Space Complexity O(1)
    def sol_1(self, nums: List[int]) -> bool:
        for i in range(len(nums)):
            for j in range(i):
                if (nums[i] == nums[j]):
                    return True
        
        return False

    # ====================================================

    ## Sol-2
    ## Sorting
    ## Time Complexity O(n*log(n))
    ## Space Complexity O(1) [if we can modify original list]
    ##                  O(n) [if we cannot modify original list]
    def sol_2(self, nums: List[int]) -> bool:
        nums.sort()
        for i in range(1, len(nums)):
            if (nums[i] == nums[i-1]):
                return True
        
        return False

    # ====================================================

    ## Sol-3
    ## Hashing
    ## Time Complexity O(n)
    ## Space Complexity O(n)
    def sol_3(self, nums: List[int]) -> bool:
        hash_set: Set[int] = set()
        for i in nums:
            if i in hash_set:
                return True
            else:
                hash_set.add(i)
        return False