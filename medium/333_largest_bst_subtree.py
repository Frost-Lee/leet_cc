class Solution:
    def dfs(self, root):
        if root is None:
            return (float('inf'), float('-inf'), 0, 0)    # min, max, largest, size
        left, right = self.dfs(root.left), self.dfs(root.right)
        new_min = min(root.val, left[0], right[0])
        new_max = max(root.val, left[1], right[1])
        new_largest = max(left[2], right[2])
        new_size = left[3] + right[3] + 1
        if left[1] < root.val and right[0] > root.val:
            new_largest = new_size
        else:
            new_min = float('-inf')
            new_max = float('inf')
            new_size = float('-inf')
        return (new_min, new_max, new_largest, new_size)

    def largestBSTSubtree(self, root: Optional[TreeNode]) -> int:
        return self.dfs(root)[2]
