import collections
class Solution:
    def findBuildings(self, heights: List[int]) -> List[int]:
        result_array = collections.deque()
        right_max_height = 0
        for i in range(len(heights) - 1, -1, -1):
            if heights[i] > right_max_height:
                result_array.appendleft(i)
            right_max_height = max(right_max_height, heights[i])
        return list(result_array)
