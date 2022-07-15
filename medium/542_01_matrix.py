import collections

class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        height, width = len(mat), len(mat[0])
        visited_mask = [[False for _ in range(width)] for _ in range(height)]
        result = [[-1 for _ in range(width)] for _ in range(height)]
        bfs_queue = collections.deque()
        distance = -1
        for i in range(height):
            for j in range(width):
                if mat[i][j] == 0:
                    visited_mask[i][j] = True
                    bfs_queue.append((i, j))
        while len(bfs_queue) > 0:
            original_length = len(bfs_queue)
            distance += 1
            for _ in range(original_length):
                row, col = bfs_queue.popleft()
                result[row][col] = distance
                for row_delta, col_delta in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    new_row, new_col = row + row_delta, col + col_delta
                    if 0 <= new_row < height and 0 <= new_col < width and not visited_mask[new_row][new_col]:
                        visited_mask[new_row][new_col] = True
                        bfs_queue.append((new_row, new_col))
        return result
