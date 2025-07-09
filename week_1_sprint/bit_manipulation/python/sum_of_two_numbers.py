# https://leetcode.com/problems/sum-of-two-integers/description/

class Solution:
    def getSum(self, a: int, b: int) -> int:
        # to get sum
        #  while b is not 0
        #   (ignoring carry) sum   = a ^ b
        #   (getting carry)  carry = (a & b) << 1
        #   a = sum
        #   b = carry

        # to get difference
        #  while b is not 0
        #   (ignoring borrow) difference = a ^ b
        #   (getting borrow)  borrow     = (~a & b) << 1
        #   a = difference
        #   b = borrow

        x: int = abs(a)
        y: int = abs(b)

        if (x < y):
            return self.getSum(b, a)
        
        sign: int = 1 if (a > 0) else -1

        if (a * b > 0):
            while y:
                sum: int = x ^ y
                carry: int = (x & y) << 1
                x = sum
                y = carry
            return sign * x
        else:
            while y:
                difference: int = x ^ y
                borrow: int = (~x & y) << 1
                x = difference
                y = borrow
            return sign * x
        
        