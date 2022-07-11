import collections

class Solution:
    def verticalOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []
        column_dict = defaultdict(list)
        bfs_queue = collections.deque()
        min_column_index, max_column_index = 0, 0
        bfs_queue.append((root, 0))
        while len(bfs_queue) > 0:
            node, column_index = bfs_queue.popleft()
            column_dict[column_index].append(node.val)
            if node.left is not None:
                bfs_queue.append((node.left, column_index - 1))
                min_column_index = min(min_column_index, column_index - 1)
            if node.right is not None:
                bfs_queue.append((node.right, column_index + 1))
                max_column_index = max(max_column_index, column_index + 1)
        return [column_dict[i] for i in range(min_column_index, max_column_index + 1)]
