from typing import List, Dict, Callable

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
       return self.stack(tokens)

    # Stack
    # Time Complexity O(n)
    # Space Complexity O(n)
    def stack(self, tokens: List[str]) -> int:
        operations: Dict[str, Callable[[int, int],int]] = {
            '+': lambda a, b : a + b,
            '-': lambda a, b : a - b,
            '*': lambda a, b : a * b,
            '/': lambda a, b : int(a / b)
        }

        stack: List[int] = []

        for token in tokens:
            if token in operations:
                number_2 = stack.pop()
                number_1 = stack.pop()
                operation = operations[token]

                stack.append(operation(number_1, number_2))
            else:
                stack.append(int(token))
        
        return stack.pop()