class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        coordinate_dict = {}
        def dfs(node, shift, depth):
            if node is None:
                return
            if shift not in coordinate_dict:
                coordinate_dict[shift] = {}
            if depth not in coordinate_dict[shift]:
                coordinate_dict[shift][depth] = []
            coordinate_dict[shift][depth].append(node.val)
            dfs(node.left, shift - 1, depth + 1)
            dfs(node.right, shift + 1, depth + 1)
        dfs(root, 0, 0)
        result = []
        for shift_key in sorted([*coordinate_dict.keys()]):
            result.append([])
            for depth_key in sorted([*coordinate_dict[shift_key].keys()]):
                result[-1] += sorted(coordinate_dict[shift_key][depth_key])
        return result
