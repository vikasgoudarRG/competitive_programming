from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        #return self.prefix(nums)
        return self.prefix_2(nums)
    
    # Product Prefix
    # Time Complexity O(n)
    # Space Complexity O(n)
    def prefix(self, nums: List[int]) -> List[int]:
        length: int = len(nums)
        l: List[int] = [0] * length
        r: List[int] = [0] * length

        l[0] = 1
        r[length - 1] = 1

        for i in range(1, length):
            l[i] = l[i-1] * nums[i - 1]
        
        for i in range(length - 2, -1, -1):
            r[i] = r[i+1] * nums[i + 1]

        ans: List[int] = [0] * length
        for i in range(length):
            ans[i] = l[i] * r[i]
        
        return ans

    # Project Prefix, with no seperate L and R prefix
    # Time Complexity O(n)
    # Space Complexity O(1)
    def prefix_2(self, nums: List[int]) -> List[int]:
        length: int = len(nums)
        ans: List[int] = [0] * length

        ans[0] = 1
        for i in range(1, length):
            ans[i] = ans[i-1] * nums[i-1]
        
        prod_right: int = 1
        for i in range(length - 1, -1, -1):
            ans[i] *= prod_right
            prod_right *= nums[i]
        
        return ans
