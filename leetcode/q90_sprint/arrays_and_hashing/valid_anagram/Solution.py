from typing import Dict


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:

        # return self.sorting(s, t)
        return self.hashing(s, t)

    # Sorting
    # Time Complexity O(n * logn)
    # Space Compelxity O(n)
    def sorting(self, s: str, t: str) -> bool:
        if (len(s) != len(t)):
            return False
        
        return sorted(s) == sorted(t)

    # HashMap
    # Time Complexity O(n)
    # Space Complexity O(n)
    def hashing(self, s: str, t: str):
        if (len(s) != len(t)):
            return False

        count: Dict[str, int] = dict()
        for ch in s:
            count[ch] = count.get(ch, 0) + 1

        for ch in t:
            if ch not in count:
                return False
            count[ch] -= 1
            if (count[ch] == 0):
                del count[ch]
        
        return True if len(count) == 0 else False
