import collections

class Solution:
    def subArrayRanges(self, nums: List[int]) -> int:
        min_sum, max_sum = 0, 0
        stack = collections.deque()
        for next_smaller in range(len(nums) + 1):
            while len(stack) > 0 and (next_smaller == len(nums) or nums[stack[-1]] > nums[next_smaller]):
                i = stack.pop()
                previous_smaller = stack[-1] if len(stack) > 0 else -1
                min_sum += nums[i] * (next_smaller - i) * (i - previous_smaller)
            stack.append(next_smaller)
        stack = collections.deque()
        for next_greater in range(len(nums) + 1):
            while len(stack) > 0 and (next_greater == len(nums) or nums[stack[-1]] < nums[next_greater]):
                i = stack.pop()
                previous_greater = stack[-1] if len(stack) > 0 else -1
                max_sum += nums[i] * (next_greater - i) * (i - previous_greater)
            stack.append(next_greater)
        return max_sum - min_sum
