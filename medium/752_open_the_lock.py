import collections

class Solution:
    def adjacent_nodes(self, node):
        result = set()
        for i in range(len(node)):
            result.add(node[:i] + str((int(node[i]) + 1) % 10) + node[i + 1:])
            result.add(node[:i] + str((int(node[i]) - 1) % 10) + node[i + 1:])
        return result

    def openLock(self, deadends: List[str], target: str) -> int:
        initial_state = '0000'
        if initial_state in deadends:
            return -1
        visited_nodes = set([initial_state])
        bfs_queue = collections.deque([initial_state])
        step_count = -1
        while len(bfs_queue) > 0:
            original_length = len(bfs_queue)
            step_count += 1
            for _ in range(original_length):
                node = bfs_queue.popleft()
                if node == target:
                    return step_count
                for adjacent_node in self.adjacent_nodes(node):
                    if adjacent_node not in visited_nodes and adjacent_node not in deadends:
                        visited_nodes.add(adjacent_node)
                        bfs_queue.append(adjacent_node)
        return -1
