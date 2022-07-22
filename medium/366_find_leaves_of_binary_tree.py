class Solution:
    def findLeaves(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []
        result = []
        def get_height(root):
            nonlocal result
            if root is None:
                return -1
            height = max(get_height(root.left), get_height(root.right)) + 1
            if len(result) == height:
                result.append([])
            result[height].append(root.val)
            return height
        get_height(root)
        return result
