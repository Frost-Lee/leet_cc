import collections

class Solution:
    def findFrequentTreeSum(self, root: Optional[TreeNode]) -> List[int]:
        sum_counter = collections.Counter()
        def subtree_sum(node):
            if node is None:
                return 0
            node_sum = node.val + subtree_sum(node.left) + subtree_sum(node.right)
            sum_counter[node_sum] += 1
            return node_sum
        subtree_sum(root)
        max_count, result = -1, []
        for tree_sum, count in sum_counter.items():
            if count > max_count:
                max_count = count
                result = [tree_sum]
            elif count == max_count:
                result.append(tree_sum)
        return result
