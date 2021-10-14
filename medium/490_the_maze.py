class Solution:
    def hasPath(self, maze, start, destination) -> bool:
        row_count, col_count = len(maze), len(maze[0])
        bfs_queue = [(start[0], start[1])]
        visited_nodes = set([(start[0], start[1])])
        while len(bfs_queue) > 0:
            row, col = bfs_queue.pop(0)
            if row == destination[0] and col == destination[1]:
                return True
            for row_delta, col_delta in [(1, 0), (0, -1), (-1, 0), (0, 1)]:
                new_row, new_col = row, col
                while 0 <= new_row < row_count and 0 <= new_col < col_count and maze[new_row][new_col] != 1:
                    new_row += row_delta
                    new_col += col_delta
                new_row -= row_delta
                new_col -= col_delta
                if (new_row, new_col) not in visited_nodes:
                    bfs_queue.append((new_row, new_col))
                    visited_nodes.add((new_row, new_col))
        return False
