from typing import Dict

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # Sorting and Equating
        # Time Complexity O(n*log(n))
        """
        if (len(s) != len(t)):
            return False
        
        s = sorted(s)
        t = sorted(t)

        if (s == t):
            return True
        return False
        """

        # Hashing 
        # Time Complexity O(n)
        ## If we know we are going to use only a fixed number of chars, we can create an array
        ## and then use indice = char - 'a' // where a -> index 0
        if (len(s) != len(t)):
            return False

        hash_map: Dict[str, int] = dict()

        for char in s:
            hash_map[char] = hash_map.get(char, 0) + 1
        
        for char in t:
            if (char not in hash_map or hash_map[char] == 0):
                return False
            hash_map[char] -= 1
        
        return True