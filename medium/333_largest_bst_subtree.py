import math

class Solution:
    def largestBSTSubtree(self, root: Optional[TreeNode]) -> int:
        max_bst_size = 0
        def dfs(node):
            nonlocal max_bst_size
            if node is None:
                return (math.inf, -math.inf, 0, True)
            left_min, left_max, left_size, left_bst = dfs(node.left)
            right_min, right_max, right_size, right_bst = dfs(node.right)
            is_bst = False
            if left_max < node.val < right_min and left_bst and right_bst:
                is_bst = True
            tree_size = left_size + right_size + 1
            if is_bst:
                max_bst_size = max(max_bst_size, tree_size)
            return (min(left_min, right_min, node.val), max(left_max, right_max, node.val), tree_size, is_bst)
        dfs(root)
        return max_bst_size
