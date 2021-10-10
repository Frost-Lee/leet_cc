class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        sorted_intervals = sorted(intervals, key=lambda x: x[0])
        interval_index_reverse_map = sorted([*range(len(intervals))], key=lambda x: intervals[x][0])
        result = []
        for interval in intervals:
            sorted_index = self._next_index(sorted_intervals, interval[1])
            if sorted_index < 0:
                result.append(sorted_index)
            else:
                result.append(interval_index_reverse_map[sorted_index])
        return result

    def _next_index(self, sorted_intervals, element):
        start, end = 0, len(sorted_intervals) - 1
        while start <= end:
            middle = (start + end) // 2
            if sorted_intervals[middle][0] > element:
                end = middle - 1
            elif sorted_intervals[middle][0] < element:
                start = middle + 1
            else:
                return middle
        if max(start, end) >= len(sorted_intervals):
            return -1
        else:
            return max(start, end)
