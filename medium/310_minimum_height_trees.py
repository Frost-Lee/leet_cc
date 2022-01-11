class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1:
            return [0]
        adjacent_list, degree_map = {i : [] for i in range(n)}, {i : 0 for i in range(n)}
        for edge in edges:
            adjacent_list[edge[0]].append(edge[1])
            adjacent_list[edge[1]].append(edge[0])
            degree_map[edge[0]] += 1
            degree_map[edge[1]] += 1
        queue = [i for i in range(n) if degree_map[i] == 1]
        excluded_node_count = 0
        while len(queue) > 0:
            if excluded_node_count + len(queue) == n:
                return queue
            temp_queue = []
            for node in queue:
                for adjacent_node in adjacent_list[node]:
                    degree_map[adjacent_node] -= 1
                    degree_map[node] -= 1
                    if degree_map[adjacent_node] == 1:
                        temp_queue.append(adjacent_node)
            excluded_node_count += len(queue)
            queue = temp_queue
