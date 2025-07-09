# https://leetcode.com/problems/number-of-1-bits/description/

class Solution:
    def hammingWeight(self, n: int) -> int:
        # looping through all bits, assuming its 32 bits
        
        # return self.sol_1(n)

        # ======================================================

        # counting number of least set significant bits, no need to worry about 32 bit or any n-bit representation

            # if you do n & (n - 1), you remove lsb set bit

        return self.sol_2(n)

    def sol_1(self, n: int) -> int:
        count: int = 0
        mask: int = 1
        
        for _ in range(32):
            if (n & mask):
                count += 1
            mask <<= 1
        
        return count

    def sol_2(self, n: int) -> int:
        count:int = 0
        while (n != 0):
            count += 1
            n = n & (n - 1)
        
        return count