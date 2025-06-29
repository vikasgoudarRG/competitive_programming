from typing import Dict, List, Tuple

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        # Method 1
        # Time Complexity O(n*k*log(k))
        """
        anagram_dict: Dict[str, List[str]] = dict()

        for s in strs:
            sorted_s = "".join(sorted(s))
            if (sorted_s not in anagram_dict):
                anagram_dict[sorted_s] = [s]
            else:
                anagram_dict[sorted_s].append(s)
        
        return list(anagram_dict.values())
        """

        # Method 2
        # Time Complexity O(n*k*log(k))
        ## same as method 1 but with keys as tuple(int)

        anagram_dict: Dict[Tuple[int, ...], List[str]] = dict()

        for s in strs:
            count: List[int] = [0]*26
            for c in s:
                count[ord(c) - ord('a')] += 1
            key: Tuple[int, ...] = tuple(count)

            if (key not in anagram_dict):
                anagram_dict[key] = [s]
            else:
                anagram_dict[key].append(s)

        return list(anagram_dict.values()) 