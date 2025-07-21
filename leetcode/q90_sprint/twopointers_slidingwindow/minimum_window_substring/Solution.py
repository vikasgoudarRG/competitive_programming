from typing import Counter, Dict, List, Tuple

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        # return self.my_solution(s, t)
        # return self.sliding_window(s, t)
        return self.sliding_window_better_in_practice(s, t)

    # Sliding Window
    # Time Complexity O(n + m)
    # Space Complexity O(n + m)
    def my_solution(self, s: str, t: str) -> str:
        if not s or not t:
            return ""

        n: int = len(s)

        freq_t: Counter[str] = Counter(t)
        freq_run: Dict[str, int] = dict()
        aim: int = len(freq_t)

        left: int = 0
        right: int = 0

        ans_left: int = 0
        ans_right: int = len(s) + 1
        got = False

        while right < n:
           
            freq_run[s[right]] = freq_run.get(s[right], 0) + 1
            if (freq_run[s[right]] == freq_t[s[right]]):
                aim -= 1
            
            if (aim == 0):
                while (left <= right):
                    if ans_right - ans_left + 1 > (right - left + 1):
                        ans_left = left
                        ans_right = right
                        got = True
                    
                    left_copy = left
                    left += 1
                    freq_run[s[left_copy]] -= 1
                    if (s[left_copy] in freq_t):
                        if (freq_run[s[left_copy]] < freq_t[s[left_copy]]):
                            aim += 1
                            break
                    
            
            right += 1
        
        if got:
            return s[ans_left: ans_right + 1]   
        else:
            return ""

    # Sliding Window 
    # Time Complexity O(n + m)
    # Space Complexity O(n + m)
    def sliding_window(self, s: str, t: str) -> str:
        if not s or not t:
            return ""

        dict_t: Counter[str] = Counter(t)

        required: int = len(dict_t)

        left: int = 0
        right: int = 0

        formed: int = 0

        window: Dict[str, int] = dict()

        ans = (float("inf"), -1, -1)

        while right < len(s):
            char: str = s[right]
            window[char] = window.get(char, 0) + 1

            if (
                char in dict_t
                and window[char] == dict_t[char]
            ):
                formed += 1

            while (left <= right and formed == required):
                char: str = s[left]

                if (right - left + 1 < ans[0]):
                    ans = (right - left + 1, left, right)
                
                window[char] -= 1
                if (
                    char in dict_t
                    and window[char] < dict_t[char]
                ):
                    formed -= 1
                
                left += 1
            
            right += 1
        
        return "" if ans[0] == float("inf") else s[ans[1]: ans[2] + 1]

    
    # Sliding Window
    #   Better in practice because the second loop is smaller because of filtering
    # Time Complexity O(n + m)
    # Space Compleixty O(n + m)
    def sliding_window_better_in_practice(self, s: str, t: str) -> str:
        if not s or not t:
            return ""

        dict_t: Counter[str] = Counter(t)
        required: int = len(dict_t)

        filtered_s: List[Tuple[int, str]] = []
        for i, char in enumerate(s):
            if char in dict_t:
                filtered_s.append((i, char))
        
        left: int = 0
        right: int = 0
        formed: int = 0
        window: Dict[str, int] = dict()

        ans = (float('inf'), -1, -1)

        while right < len(filtered_s):
            char: str = filtered_s[right][1]
            window[char] = window.get(char, 0) + 1

            if (window[char] == dict_t[char]):
                formed += 1
            
            while left <= right and formed == required:
                char: str = filtered_s[left][1]

                start: int = filtered_s[left][0]
                end: int = filtered_s[right][0]

                if (end - start + 1 < ans[0]):
                    ans = (end - start + 1, start, end)
                
                window[char] -= 1
                if (window[char] < dict_t[char]):
                    formed -= 1
                
                left += 1
            right += 1
        
        return "" if ans[0] == float('inf') else s[ans[1]: ans[2] + 1]
