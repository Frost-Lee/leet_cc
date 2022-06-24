import collections

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        monotonic_stack = collections.deque()
        max_area = 0
        for next_smaller in range(len(heights) + 1):
            while len(monotonic_stack) > 0 and (next_smaller == len(heights) or heights[next_smaller] < heights[monotonic_stack[-1]]):
                i = monotonic_stack.pop()
                previous_smaller = monotonic_stack[-1] if len(monotonic_stack) > 0 else -1
                max_area = max(max_area, heights[i] * (next_smaller - previous_smaller - 1))
            monotonic_stack.append(next_smaller)
        return max_area
