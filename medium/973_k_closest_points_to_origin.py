class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        distance_squared_list = [*map(lambda x: (x[0] ** 2 + x[1] ** 2, x), points)]
        heapq.heapify(distance_squared_list)
        result = []
        for _ in range(k):
            result.append(heapq.heappop(distance_squared_list)[1])
        return result
