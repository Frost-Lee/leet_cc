import collections

class Solution:
    def maxResult(self, nums: List[int], k: int) -> int:
        dp_array = [0 for _ in range(len(nums))]
        dp_array[0] = nums[0]
        decreasing_queue = collections.deque([0])
        for i in range(1, len(nums)):
            while len(decreasing_queue) > 0 and decreasing_queue[0] < i - k:
                decreasing_queue.popleft()
            dp_array[i] = dp_array[decreasing_queue[0]] + nums[i]
            while len(decreasing_queue) > 0 and dp_array[decreasing_queue[-1]] <= dp_array[i]:
                decreasing_queue.pop()
            decreasing_queue.append(i)
        return dp_array[-1]
