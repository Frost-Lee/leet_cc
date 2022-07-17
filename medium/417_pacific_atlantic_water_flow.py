import collections
import copy

class Solution:
    def bfs(self, initial_sources, graph):
        height, width = len(graph), len(graph[0])
        bfs_queue = collections.deque(initial_sources)
        for row, col in initial_sources:
            graph[row][col] = -graph[row][col]
        while len(bfs_queue) > 0:
            row, col = bfs_queue.popleft()
            for row_delta, col_delta in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                new_row, new_col = row + row_delta, col + col_delta
                if 0 <= new_row < height and 0 <= new_col < width and graph[new_row][new_col] > 0:
                    if graph[new_row][new_col] < abs(graph[row][col]):
                        continue
                    graph[new_row][new_col] = -graph[new_row][new_col]
                    bfs_queue.append((new_row, new_col))

    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        pacific_graph = copy.deepcopy(heights)
        atlantic_graph = copy.deepcopy(heights)
        pacific_sources, atlantic_sources = [], []
        height, width = len(heights), len(heights[0])
        for i in range(height):
            for j in range(width):
                pacific_graph[i][j] += 1
                atlantic_graph[i][j] += 1
        for i in range(width):
            pacific_sources.append((0, i))
            atlantic_sources.append((height - 1, i))
        for i in range(1, height):
            pacific_sources.append((i, 0))
            atlantic_sources.append((i - 1, width - 1))
        self.bfs(pacific_sources, pacific_graph)
        self.bfs(atlantic_sources, atlantic_graph)
        result = []
        for i in range(height):
            for j in range(width):
                if pacific_graph[i][j] < 0 and atlantic_graph[i][j] < 0:
                    result.append((i, j))
        return result
