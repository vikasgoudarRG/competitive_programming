# https://leetcode.com/problems/longest-repeating-character-replacement/description/

from typing import Set, Dict

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        # Sliding Window + Binary Search
        # Time Complexity O(logn * n)
        # Space Complexity O(m),
        #                       m -> size of charset


        ## return self.sol_1(s, k)

        # ========================================

        # Sliding Window
        # Time Complexity O(n*m),
        #                        n -> size of string
        #                        m -> size of charset
        # Space Complexity: O(m)

        ## return self.sol_2(s, k)

        # Sliding window 
        # Time Complexity O(n)
        # Space Complexity O(m), m -> size of charset

        return self.sol_3(s, k)

    def sol_1(self, s: str, k: int) -> int:
        low: int = 1
        high: int = len(s) + 1

        while (low < high):
            mid: int = low + (high - low) // 2

            if self.can_make_valid_substring(s, mid, k):
                low = mid + 1
            else:
                high = mid
        
        return low - 1

    def can_make_valid_substring(self, s: str, mid: int, k: int) -> bool:
        freq_map: Dict[str, int] = dict()
        max_frequency: int = 0
        left: int = 0
        for right in range(len(s)):
            freq_map[s[right]] = freq_map.get(s[right], 0) + 1

            if (right - left + 1 > mid):
                freq_map[s[left]] -= 1
                left += 1
            
            max_frequency = max(max_frequency, freq_map[s[right]])
            if (mid - max_frequency <= k):
                return True
        
        return False

    def sol_2(self, s: str, k: int) -> int:
        all_letters: Set[str] = set(s)
        max_length: int = 0

        for letter in all_letters:
            left: int = 0
            count: int = 0

            for right in range(len(s)):
                if (s[right] == letter):
                    count += 1
                
                while not self._is_valid_window(left, right, count, k):
                    if s[left] == letter:
                        count -= 1
                    left += 1
                
                max_length = max(max_length, right - left + 1)
        return max_length

    def _is_valid_window(self, left: int, right: int, count: int, k: int):
        return right - left + 1 - count <= k
    
    def sol_3(self, s: str, k: int) -> int:
        max_frequency: int = 0
        freq_map: Dict[str, int] = dict()
        left: int = 0
        ans: int = 0
        
        for right in range(len(s)):
            freq_map[s[right]] = freq_map.get(s[right], 0) + 1

            max_frequency = max(max_frequency, freq_map[s[right]])

            if not (right - left + 1 - max_frequency <= k):
                freq_map[s[left]] -= 1
                left += 1
            
            ans = right - left + 1
        
        return ans

