import collections

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        node_parent_map = {}
        def dfs_set_parent(node, parent):
            nonlocal node_parent_map
            if node is None:
                return
            node_parent_map[node] = parent
            dfs_set_parent(node.left, node)
            dfs_set_parent(node.right, node)
        dfs_set_parent(root, None)
        visited_set = set([target])
        bfs_queue = collections.deque([target])
        while k > 0:
            original_length = len(bfs_queue)
            for _ in range(original_length):
                node = bfs_queue.popleft()
                for adjacent_node in [node.left, node.right, node_parent_map[node]]:
                    if adjacent_node is not None and adjacent_node not in visited_set:
                        visited_set.add(adjacent_node)
                        bfs_queue.append(adjacent_node)
            k -= 1
        return [*map(lambda x: x.val, bfs_queue)]
