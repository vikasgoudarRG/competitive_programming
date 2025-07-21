from typing import List #, Tuple

# My Solution
# Time Complexity O(1) for all operations
# Space Complexity O(n)
'''
class MinStack:
    # Entries -> (val, min_so_far)
    def __init__(self):
       self._list: List[Tuple[int, int]] = [] 

    def push(self, val: int) -> None:
        if not self._list:
            self._list.append((val, val))
        else:
            self._list.append((val, min(self._list[-1][1], val)))

    def pop(self) -> None:
        self._list.pop()

    def top(self) -> int:
        return self._list[-1][0]

    def getMin(self) -> int:
        return self._list[-1][1]
'''

# Two Stacks 
    # More Memory efficient than storing minimum everytime
# Time Complexity O(1)
# Space Complexity O(n)
'''
class MinStack:
    def __init__(self):
        self._min_stack: List[int] = []
        self._stack: List[int] = []
    
    def push(self, val: int) -> None:
        self._stack.append(val)
        if not self._min_stack or val <= self._min_stack[-1]:
            self._min_stack.append(val)
    
    def pop(self) -> None:
        val: int = self._stack.pop()
        if (self._min_stack[-1] == val):
            del self._min_stack[-1]

    def top(self) -> int:
        return self._stack[-1]

    def getMin(self) -> int:
        return self._min_stack[-1]
'''

# Two Stacks, more memory efficient than previous two stacks method
# Time Complexity O(1)
# Space Complexity O(n)

class MinStack:
    # Entries for min stack 
    # [min, freq]
    def __init__(self):
        self._stack: List[int] = []
        self._min_stack: List[List[int]] = []
    
    def push(self, val: int) -> None:
        self._stack.append(val)

        if not self._min_stack or self._min_stack[-1][0] > val:
            self._min_stack.append([val, 1])
        
        elif self._min_stack[-1][0] == val:
            self._min_stack[-1][1] += 1
    
    def pop(self) -> None:
        val: int = self._stack.pop()
        if self._min_stack[-1][0] == val:
            self._min_stack[-1][1] -= 1

            if self._min_stack[-1][1] == 0:
                del self._min_stack[-1]
    
    def top(self) -> int:
        return self._stack[-1]
    
    def getMin(self) -> int:
        return self._min_stack[-1][0]

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()