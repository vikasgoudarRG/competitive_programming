# https://leetcode.com/problems/valid-palindrome/description/

class Solution:
    def isPalindrome(self, s: str) -> bool:
        # 2 pointers
        # Time Complexity O(n)
        # Space Complexity O(1)
        
        i: int = 0
        j: int = len(s) - 1

        while i < j:
            if not s[i].isalnum():
                i += 1
                continue
            if not s[j].isalnum():
                j -= 1
                continue
            
            if s[i].lower() != s[j].lower():
                return False
            i += 1
            j -= 1
        
        return True
            