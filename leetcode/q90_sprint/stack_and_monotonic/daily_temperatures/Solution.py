from typing import List 

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        # return self.stack(temperatures)
        return self.dp(temperatures)

    # Time Complexity O(n)
    # Space Complexity O(n)
    def stack(self, temperatures: List[int]) -> List[int]:
        _stack: List[int] = []
        ans = [0] * len(temperatures)

        for curr_day, temp in enumerate(temperatures):
            while _stack and temperatures[_stack[-1]] < temp:
                prev_day = _stack.pop()
                ans[prev_day] = curr_day - prev_day

            _stack.append(curr_day)

        return ans 

    # Time Complexity O(n)
    # Space Complexity O(1)
    def dp(self, temperatures: List[int]) -> List[int]:
        n: int = len(temperatures)
        ans: List[int] = [0] * n

        hottest_so_far: int = -1

        for curr_day in range(n - 1, -1, -1):
            curr_temp: int = temperatures[curr_day]

            if curr_temp >= hottest_so_far:
                hottest_so_far = curr_temp
                continue

            days = 1
            while temperatures[curr_day + days] <= curr_temp:
                days += ans[curr_day + days]
            
            ans[curr_day] = days
        
        return ans

            
