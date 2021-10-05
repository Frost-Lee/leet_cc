class Solution:
    def dfs(self, root, path_digits):
        if root.left is None and root.right is None:
            self.numbers_sum += int(''.join(path_digits + [str(root.val)]))
        else:
            if root.left is not None:
                self.dfs(root.left, path_digits + [str(root.val)])
            if root.right is not None:
                self.dfs(root.right, path_digits + [str(root.val)])

    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        self.numbers_sum = 0
        self.dfs(root, [])
        return self.numbers_sum
