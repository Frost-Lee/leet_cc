class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        insertion_index = 0
        start, end = 0, len(intervals) - 1
        while start <= end:
            mid = (end - start) // 2 + start
            if intervals[mid][0] == newInterval[0]:
                insertion_index = mid
                break
            elif intervals[mid][0] > newInterval[0]:
                end = mid - 1
                insertion_index = start
            elif intervals[mid][0] < newInterval[0]:
                start = mid + 1
                insertion_index = start
        merged_intervals = intervals[:insertion_index]
        unmerged_intervals = [newInterval] + intervals[insertion_index:]
        for index, interval in enumerate(unmerged_intervals):
            if len(merged_intervals) == 0 or interval[0] > merged_intervals[-1][1]:
                if index > 0:
                    merged_intervals = merged_intervals + unmerged_intervals[index:]
                    break
                else:
                    merged_intervals.append(interval)
            else:
                merged_intervals[-1][1] = max(merged_intervals[-1][1], interval[1])
        return merged_intervals
