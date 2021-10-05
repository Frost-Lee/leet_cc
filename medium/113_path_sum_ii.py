class Solution:
    def dfs(self, root, target_sum, path_sum, path_nodes):
        if root.left is None and root.right is None:
            if path_sum + root.val == target_sum:
                self.paths.append(path_nodes + [root.val])
        else:
            if root.left is not None:
                self.dfs(root.left, target_sum, path_sum + root.val, path_nodes + [root.val])
            if root.right is not None:
                self.dfs(root.right, target_sum, path_sum + root.val, path_nodes + [root.val])

    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:        
        if root is None:
            return []
        self.paths = []
        self.dfs(root, targetSum, 0, [])
        return self.paths
