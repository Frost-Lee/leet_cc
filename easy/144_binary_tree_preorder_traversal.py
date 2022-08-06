import collections

class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        traversal_stack = [root] if root is not None else []
        while len(traversal_stack) > 0:
            node = traversal_stack.pop()
            result.append(node.val)
            if node.right is not None:
                traversal_stack.append(node.right)
            if node.left is not None:
                traversal_stack.append(node.left)
        return result
