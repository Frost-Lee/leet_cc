class Solution:
    def dfs(self, grid, source, island_identifier):
        row_count, col_count = len(grid), len(grid[0])
        grid[source[0]][source[1]] = -1
        for row_delta, col_delta, dir_name in [(1, 0, 'd'), (0, -1, 'l'), (-1, 0, 'u'), (0, 1, 'r')]:
            new_source = (source[0] + row_delta, source[1] + col_delta)
            if 0 <= new_source[0] < row_count and 0 <= new_source[1] < col_count:
                if grid[new_source[0]][new_source[1]] > 0:
                    island_identifier = self.dfs(grid, new_source, island_identifier + dir_name)
                    island_identifier += '|'
        return island_identifier

    def numDistinctIslands(self, grid: List[List[int]]) -> int:
        identifier_set = set()
        row_count, col_count = len(grid), len(grid[0])
        for i in range(row_count):
            for j in range(col_count):
                if grid[i][j] > 0:
                    identifier = self.dfs(grid, (i, j), '')
                    identifier_set.add(identifier)
        return len(identifier_set)
