# https://leetcode.com/problems/reverse-bits/description/

import functools

class Solution:
    def reverseBits(self, n: int) -> int:
        # Looping through bits
        # Time Complexity O(1)
        # Space Complexity O(1)

        ## return self.sol_1(n)

        # =========================

        # Looping through bytes, great for memoization
        # Time Complexity O(1)
        # Space Complexity O(1), since cache is fixed size of 2^8

        ## return self.sol_2(n)

        # =========================
        
        # mask and shift
        # Time Complexity O(1)
        # Space Complexity O(1)

        return self.sol_3(n)


    def sol_1(self, n: int) -> int:
        result: int = 0
        power: int = 31

        while (n):
            result |= (n & 1) << power
            n >>= 1
            power -=1
        
        return result
        
    def sol_2(self, n: int) -> int:
        result: int = 0
        power: int = 24
        while (n):
            result |= self.reverse_byte(n & 0xFF) << power
            n >>= 8
            power -= 8
        
        return result

    @functools.lru_cache(maxsize = None)
    def reverse_byte(self, byte: int) -> int:
        result: int = 0
        power: int = 7

        while (byte):
            result |= (byte & 1) << power
            byte >>= 1
            power -= 1
        
        return result

    def sol_3(self, n: int) -> int:
        n = (n >> 16) | (n << 16)
        n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8)
        n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4)
        n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2)
        n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1)

        return n
