class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        prefix_sum_counter = Counter()
        hit_count = 0
        def dfs(root, current_sum):
            nonlocal prefix_sum_counter, hit_count
            if root is None:
                return
            current_sum += root.val
            if current_sum == targetSum:
                hit_count += 1
            hit_count += prefix_sum_counter[current_sum - targetSum]
            prefix_sum_counter[current_sum] += 1
            dfs(root.left, current_sum)
            dfs(root.right, current_sum)
            prefix_sum_counter[current_sum] -= 1
        dfs(root, 0)
        return hit_count
