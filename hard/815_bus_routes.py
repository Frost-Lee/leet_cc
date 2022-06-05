class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        if source == target:
            return 0
        graph_nodes = {i : set(l) for i, l in enumerate(routes)}
        adjacent_matrix = [[True if i > j and (graph_nodes[i] & graph_nodes[j]) else False for i in range(len(routes))] for j in range(len(routes))]
        initial_keys = set([k for k in graph_nodes.keys() if source in graph_nodes[k]])
        bfs_queue = list(initial_keys)
        visit_mask = [i in initial_keys for i in range(len(routes))]
        transfer_count = 1
        while len(bfs_queue) > 0:
            new_bfs_queue = []
            for k in bfs_queue:
                if target in graph_nodes[k]:
                    return transfer_count
                else:
                    for i in range(len(routes)):
                        if not visit_mask[i] and (adjacent_matrix[k][i] or adjacent_matrix[i][k]):
                            new_bfs_queue.append(i)
                            visit_mask[i] = True
            bfs_queue = new_bfs_queue
            transfer_count += 1
        return -1
