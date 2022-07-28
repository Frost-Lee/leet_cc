class Solution:
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        if root is None:
            return []
        forest_roots = []
        to_delete_val_set = set(to_delete)
        def dfs(node, parent):
            nonlocal forest_roots, to_delete_val_set
            if node is None:
                return
            parent_deleted = parent is not None and parent.val in to_delete_val_set
            self_delete = node.val in to_delete_val_set
            if (parent is None or parent_deleted) and not self_delete:
                forest_roots.append(node)
            if self_delete and parent is not None:
                if parent.left is node:
                    parent.left = None
                elif parent.right is node:
                    parent.right = None
            dfs(node.left, node)
            dfs(node.right, node)
        dfs(root, None)
        return forest_roots
