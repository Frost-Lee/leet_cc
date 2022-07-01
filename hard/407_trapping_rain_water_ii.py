import heapq

class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        height, width = len(heightMap), len(heightMap[0])
        if width <= 2 or height <= 2:
            return 0
        heap = []
        visited_mask = [[False for _ in range(width)] for _ in range(height)]
        for i in range(width):
            heap.append((heightMap[0][i], 0, i))
            visited_mask[0][i] = True
            heap.append((heightMap[height - 1][i], height - 1, i))
            visited_mask[height - 1][i] = True
        for i in range(1, height - 1):
            heap.append((heightMap[i][0], i, 0))
            visited_mask[i][0] = True
            heap.append((heightMap[i][width - 1], i, width - 1))
            visited_mask[i][width - 1] = True
        heapq.heapify(heap)
        total_trap = 0
        level = 0
        while len(heap) > 0:
            min_height, row, col = heapq.heappop(heap)
            level = max(min_height, level)
            for new_row, new_col in [(row + 1, col), (row - 1, col), (row, col + 1), (row, col - 1)]:
                if 0 <= new_row < height and 0 <= new_col < width and not visited_mask[new_row][new_col]:
                    heapq.heappush(heap, (heightMap[new_row][new_col], new_row, new_col))
                    visited_mask[new_row][new_col] = True
                    if heightMap[new_row][new_col] < level:
                        total_trap += (level - heightMap[new_row][new_col])
        return total_trap
