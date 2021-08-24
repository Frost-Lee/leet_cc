class Solution:
    def employeeFreeTime(self, schedule: '[[Interval]]') -> '[Interval]':
        schedule = sorted(functools.reduce(lambda x, y: x + y, schedule), key=lambda x: x.start)
        if len(schedule) == 0:
            return []
        lastBusyTime = schedule[0].end
        freeIntervals = []
        for interval in schedule[1:]:
            if interval.start > lastBusyTime:
                freeIntervals.append(Interval(lastBusyTime, interval.start))
                lastBusyTime = interval.end
            else:
                lastBusyTime = max(lastBusyTime, interval.end)
        return freeIntervals
