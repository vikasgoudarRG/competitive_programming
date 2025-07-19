from typing import Dict


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        return self.sliding_window(s)

    
    # Sliding Window
    # Time Complexity O(n)
    # Space Complexity O(n)
    def sliding_window(self, s: str) -> int:
        seen: Dict[str, int] = dict()

        left: int = 0
        right: int = 0
        ans: int = 0

        while right < len(s):
            if (s[right] in seen and seen[s[right]] >= left):
                left = seen[s[right]] + 1
            
            
            seen[s[right]] = right
            
            ans = max(ans, right - left + 1)

            right += 1
        
        return ans
            
                