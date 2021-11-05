class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        row_count, col_count = len(grid), len(grid[0])
        bfs_queue, fresh_count = [], 0
        for i in range(row_count):
            for j in range(col_count):
                if grid[i][j] == 2:
                    bfs_queue.append((i, j))
                elif grid[i][j] == 1:
                    fresh_count += 1
        if fresh_count == 0:
            return 0
        minute_count = 0
        while len(bfs_queue) > 0:
            queue_length = len(bfs_queue)
            for _ in range(queue_length):
                row_index, col_index = bfs_queue.pop(0)
                for row_delta, col_delta in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                    new_row_index, new_col_index = row_index + row_delta, col_index + col_delta
                    if 0 <= new_row_index < row_count and 0 <= new_col_index < col_count:
                        if grid[new_row_index][new_col_index] == 1:
                            grid[new_row_index][new_col_index] = 2
                            bfs_queue.append((new_row_index, new_col_index))
            minute_count += 1
        for i in range(row_count):
            for j in range(col_count):
                if grid[i][j] == 1:
                    return -1
        return minute_count - 1
