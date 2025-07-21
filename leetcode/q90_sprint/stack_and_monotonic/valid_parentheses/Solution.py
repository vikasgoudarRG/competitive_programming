from typing import List, Dict

class Solution:
    def isValid(self, s: str) -> bool:
       return self.my_solution(s)

    # Stack
    # Time Complexity O(n)
    # Space Complexity O(n)
    def my_solution(self, s: str) -> bool:
        complement: Dict[str, str] = {
            '}': '{',
            ']': '[',
            ')': '('
        }

        stack: List[str] = []

        for char in s:
            if char in complement:
                top: str = stack[-1] if stack else "#"

                if complement[char] == top:
                    del stack[-1]
                else:
                    return False
            else:
                stack.append(char)
            
        return not stack
