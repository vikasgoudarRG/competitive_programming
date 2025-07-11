# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_so_far: int = prices[0]
        max_profit: int = 0

        for i in prices:
            if (i < min_so_far):
                min_so_far = i
            
            if (i - min_so_far > max_profit):
                max_profit = i - min_so_far
        return max_profit
        