# https://leetcode.com/problems/counting-bits/description/

from typing import List

class Solution:
    def countBits(self, n: int) -> List[int]:
        # PopCount
        # Time Complexity O(n * logn)
        # Space Complexity O(1)

        ## return self.sol_1(n)

        # =====================================================

        # DP + MSB
        # Time Complexity O(n)
        # Space Complexity O(1)
            # PopCount(x + b) = PopCount(x) + 1,
            #                                   b = 2m
            #                                   x < b
        ## return self.sol_2(n)

        # =====================================================

        # DP + LSB
        # Time Complexity O(n)
        # Space Complexity O(1)
            # PopCount(x) = PopCount(x//2) + (x & 1)
            # because dividing by 2 can be considered as removing LSB
        
        ## return self.sol_3(n)

        # ====================================================
        # DP + LSB
        # Time Complexity O(n)
        # Space Complexity O(1)
            # PopCount(x) = PopCount(x & (x - 1)) + 1
            # since, x & (x - 1) -> removes least significant set bit
        
        return  self.sol_4(n)


    def sol_1(self, n: int) -> List[int]:
        arr: List[int] = []
        for i in range(n + 1):
            arr.append(self.popcount(i))
        return arr

    def popcount(self, n: int) -> int:
        count: int = 0
        while (n):
            count +=1
            n = n & (n - 1)
        return count

    def sol_2(self, n: int) -> List[int]:
        ans: List[int] = [0] * (n + 1)
        base: int = 1
        offset: int = 0

        while (base <= n):
            while (offset < base and base + offset <= n):
                ans[base + offset] = 1 + ans[offset]
                offset += 1
            offset = 0
            base <<= 1
        
        return ans

    def sol_3(self, n: int) -> List[int]:
        ans: List[int] = [0] * (n + 1)
        for i in range(1, n + 1):
            ans[i] = ans[i//2] + (i & 1)
        return ans

    def sol_4(self, n: int) -> List[int]:
        ans: List[int] = [0] * (n + 1)

        for i in range(1, n + 1):
            ans[i] = ans[i & (i - 1)] + 1
        
        return ans