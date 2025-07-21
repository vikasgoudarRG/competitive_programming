from typing import Dict


class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        return self.binary_search(s, k)
        # return self.sliding_window(s, k)

    # Sliding Window
    # Time Complexity O(n)
    # Space Complexity O(n)
    def sliding_window(self, s: str, k: int) -> int:
        max_freq: int = 0
        freq: Dict[str, int] = dict()
        left: int = 0
        right: int = 0
        longest: int = 0
        n: int = len(s)

        while right < n:
            char: str = s[right]
            freq[char] = freq.get(char, 0) + 1
            max_freq = max(max_freq, freq[char])

            while (right - left + 1 - max_freq > k):
                freq[s[left]] -= 1
                left += 1

            longest = max(longest, right - left + 1)
            right += 1
        return longest

    # Binary Search
    # Time Complexity O(n * logn)
    # Space Complexity O(m), m = 26 {character set}
    def binary_search(self, s: str, k: int) -> int:
        def _can_make(s: str, m: int, k: int) -> bool:
            freq_map: Dict[str, int] = dict()
            start: int = 0
            end: int = 0
            max_frequency: int = 0
            n: int = len(s)

            while (end < n):
                freq_map[s[end]] = freq_map.get(s[end], 0) + 1

                if (end - start + 1 > m):
                    freq_map[s[start]] -= 1
                    start += 1
                
                max_frequency = max(max_frequency, freq_map[s[end]])
                
                if (m - max_frequency <= k):
                    return True
                
                end += 1
            
            return False
            
            
        low: int = 1
        high: int = len(s) + 1

        while (low < high):
            mid: int = low + (high - low) // 2 
            if (_can_make(s, mid, k)):
                low = mid + 1
            else:
                high = mid

        return low - 1

    
