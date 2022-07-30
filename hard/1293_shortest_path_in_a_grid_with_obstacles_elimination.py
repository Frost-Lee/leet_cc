import collections

class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        height, width = len(grid), len(grid[0])
        bfs_queue = collections.deque([(0, 0, k)])
        visited_nodes = set([(0, 0, k)])
        distance = -1
        while len(bfs_queue) > 0:
            original_length = len(bfs_queue)
            distance += 1
            for _ in range(original_length):
                row, col, quota = bfs_queue.popleft()
                if row == height - 1 and col == width - 1:
                    return distance
                for row_delta, col_delta in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                    new_row, new_col = row + row_delta, col + col_delta
                    if 0 <= new_row < height and 0 <= new_col < width:
                        new_quota = quota if grid[new_row][new_col] == 0 else quota - 1
                        new_node = (new_row, new_col, new_quota)
                        if new_node not in visited_nodes and new_quota >= 0:
                            visited_nodes.add(new_node)
                            bfs_queue.append(new_node)
        return -1
