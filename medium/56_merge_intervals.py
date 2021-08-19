class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals, key=lambda x: x[0])
        merged_intervals = []
        for interval in intervals:
            if len(merged_intervals) == 0 or interval[0] > merged_intervals[-1][1]:
                merged_intervals.append(interval)
            else:
                merged_intervals[-1][1] = max(merged_intervals[-1][1], interval[1])
        return merged_intervals
