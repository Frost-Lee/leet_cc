class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result_list, bfs_queue = [], []
        if root is None:
            return result_list
        bfs_queue.append(root)
        while len(bfs_queue) > 0:
            temp_queue, level_numbers = [], []
            while len(bfs_queue) > 0:
                visited_node = bfs_queue.pop(0)
                level_numbers.append(visited_node.val)
                if visited_node.left is not None:
                    temp_queue.append(visited_node.left)
                if visited_node.right is not None:
                    temp_queue.append(visited_node.right)
            result_list.append(level_numbers)
            bfs_queue = temp_queue
        return result_list
