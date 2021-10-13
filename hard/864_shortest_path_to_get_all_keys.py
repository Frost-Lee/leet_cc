class Solution:
    def shortestPathAllKeys(self, grid: List[str]) -> int:
        start_location, key_count = None, 0
        row_count, col_count = len(grid), len(grid[0])
        for i in range(row_count):
            for j in range(col_count):
                if grid[i][j] == '@':
                    start_location = (i, j)
                elif ord('a') <= ord(grid[i][j]) <= ord('z'):
                    key_count += 1
        bfs_queue = [(start_location[0], start_location[1], 0, '')]
        visited_nodes = set()
        visited_nodes.add((start_location[0], start_location[1], ''))
        while len(bfs_queue) > 0:
            row_index, col_index, path_length, keys = bfs_queue.pop(0)
            if len(keys) == key_count:
                return path_length
            for row_delta, col_delta in [(1, 0), (0, -1), (-1, 0), (0, 1)]:
                new_row_index, new_col_index = row_index + row_delta, col_index + col_delta
                if 0 <= new_row_index < row_count and 0 <= new_col_index < col_count:
                    new_element = grid[new_row_index][new_col_index]
                    new_keys = keys
                    if ord('a') <= ord(new_element) <= ord('z') and new_element not in keys:
                        new_keys += new_element
                        new_keys = ''.join(sorted(new_keys))
                    if not (new_element == '#' or (ord('A') <= ord(new_element) <= ord('Z') and new_element.lower() not in keys)):
                        if (new_row_index, new_col_index, keys) not in visited_nodes:
                            bfs_queue.append((new_row_index, new_col_index, path_length + 1, new_keys))
                            visited_nodes.add((new_row_index, new_col_index, keys))
        return -1
