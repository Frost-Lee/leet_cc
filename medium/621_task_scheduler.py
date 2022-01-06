class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        frequencies = sorted([*Counter(tasks).values()])
        max_frequency = frequencies.pop()
        idle_time = (max_frequency - 1) * n
        while len(frequencies) > 0 and idle_time > 0:
            idle_time -= min(max_frequency - 1, frequencies.pop())
        idle_time = max(0, idle_time)
        return max(idle_time, 0) + len(tasks)
