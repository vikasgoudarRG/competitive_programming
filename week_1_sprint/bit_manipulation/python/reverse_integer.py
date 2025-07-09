# https://leetcode.com/problems/reverse-integer/description/

class Solution:
    def reverse(self, x: int) -> int:
        # Popping digits from num
        # Time Complexity O(log n),
        #                          because number has log(base 10) digits
        # Space Complexity O(1)

        INT_MAX = 2**31 - 1
        INT_MIN = -2**31

        ans: int = 0

        while (x):
            pop: int = x % 10 if x > 0 else x % -10
            x = x // 10 if x > 0 else (x - pop) // 10
            
            if (ans > INT_MAX // 10 or (ans == INT_MAX // 10 and pop > INT_MAX % 10)):
                return 0
            if (ans < (INT_MIN - INT_MIN % -10) // 10 or (ans == (INT_MIN - INT_MIN % -10) // 10 and pop < INT_MIN % -10)):
                return 0

            ans = ans * 10 + pop

        return ans
        