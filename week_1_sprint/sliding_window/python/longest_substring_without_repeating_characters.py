# https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

from typing import DefaultDict, Dict
from collections import defaultdict

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # Sliding Window - Frequency
        # Time Complexity  O(n)
        # Space Complexity O(min(n, m)), 
        #                               n -> size of string
        #                               m -> size of charset

        ## return self.sol_1(s)

        # ==========================

        # Sliding Window Optimized - Index
        # Time Complexity O(n)
        # Space Complexity O(min(n, m)), 
        #                               n -> size of string
        #    
        
        return self.sol_2(s)
    
    def sol_1(self, s: str) -> int:
        hash: DefaultDict[str, int] = defaultdict(int)
        max_length: int = 0

        left: int = 0
        right: int = 0

        while (right < len(s)):
            r: str = s[right]
            hash[r] += 1

            while (hash[r] > 1):
                l: str = s[left]
                hash[l] -= 1
                left += 1
            
            max_length = max(max_length, right - left + 1)
            
            right += 1
        return max_length
                
    def sol_2(self, s: str) -> int:
        hash: Dict[str, int] = dict()
        left: int = 0
        right: int = 0
        max_length: int = 0

        while (right < len(s)):
            c: str = s[right]

            if (c in hash and hash[c] >= left):
                left = hash[c] + 1

            hash[c] = right
            max_length = max(max_length, right - left + 1)
            right += 1
        return max_length
