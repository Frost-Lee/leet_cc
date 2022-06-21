import collections

class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        bfs_queue = collections.deque()
        row_count, col_count = len(grid), len(grid[0])
        visited_mask = [[False for i in range(col_count)] for i in range(row_count)]
        if grid[0][0] == 1 or grid[row_count - 1][col_count - 1] == 1:
            return -1
        bfs_queue.append(((0, 0), 1))
        visited_mask[0][0] = True
        while len(bfs_queue) > 0:
            popped_node, distance = bfs_queue.popleft()
            if popped_node == (row_count - 1, col_count - 1):
                return distance
            for row_delta, col_delta in [(0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1), (-1, 0), (-1, 1)]:
                new_row, new_col = popped_node[0] + row_delta, popped_node[1] + col_delta
                if 0 <= new_row < len(grid) and 0 <= new_col < len(grid[0]) and grid[new_row][new_col] == 0 and not visited_mask[new_row][new_col]:
                    bfs_queue.append(((new_row, new_col), distance + 1))
                    visited_mask[new_row][new_col] = True
        return -1
