import collections

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []
        result, bfs_queue = [], collections.deque()
        bfs_queue.append(root)
        while len(bfs_queue) > 0:
            original_length = len(bfs_queue)
            result_element = []
            for i in range(original_length):
                node = bfs_queue.popleft()
                result_element.append(node.val)
                if node.left is not None:
                    bfs_queue.append(node.left)
                if node.right is not None:
                    bfs_queue.append(node.right)
            result.append(result_element)
        return result
