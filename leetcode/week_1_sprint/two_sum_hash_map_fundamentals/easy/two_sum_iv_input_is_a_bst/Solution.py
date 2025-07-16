from collections import deque
from typing import Set, Optional, Deque, List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val: int=0, left: Optional["TreeNode"]=None, right: Optional["TreeNode"]=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        # BFS and HashSet
        # Time Complexity O(n)
        # Space Complexity O(n)
        ## return self.approach_1(root, k)


        # DFS and HashSet
        # Time Complexity O(n)
        # Space Complexity O(n)
        ## return self.approach_2(root, k)

        # BST in-order traversal
        # Time Complexity O(n)
        # Space Complexity O(n)
        return self.approach_3(root, k)
    
    def approach_1(self, root: Optional[TreeNode], k: int) -> bool:
        seen: Set[int] = set()

        def dfs(node: Optional[TreeNode]) -> bool:
            if (not node):
                return False

            complement: int = k - node.val

            if (complement in seen):
                return True
            
            seen.add(node.val)

            return dfs(node.left) | dfs(node.right)
        
        return dfs(root)
    
    def approach_2(self, root: Optional[TreeNode], k: int) -> bool:
        seen: Set[int] = set()
        queue: Deque[Optional[TreeNode]] = deque([root])

        while (queue):
            node: Optional[TreeNode] = queue.popleft()
            if (not node):
                continue
            
            complement: int = k - node.val

            if (complement in seen):
                return True
            
            seen.add(node.val)

            queue.extend([node.left, node.right])
        
        return False

    def approach_3(self, root: Optional[TreeNode], k: int) -> bool:
        nodes_sorted: List[int] = []

        def inorder(node: Optional[TreeNode]) -> None:
            if (not node):
                return
            
            inorder(node.left)
            nodes_sorted.append(node.val)
            inorder(node.right)

            return
        
        inorder(root)
        
        low: int = 0
        high: int = len(nodes_sorted) - 1

        while (low < high):
            sum: int = nodes_sorted[low] + nodes_sorted[high]
            if (sum == k):
                return True
            elif (sum > k):
                high -= 1
            
            else:
                low += 1
            
        return False

