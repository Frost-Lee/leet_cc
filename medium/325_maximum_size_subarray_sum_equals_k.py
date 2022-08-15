class Solution:
    def maxSubArrayLen(self, nums: List[int], k: int) -> int:
        prefix_sum = 0
        max_length = 0
        prefix_sum_map = {}
        for i in range(len(nums)):
            prefix_sum += nums[i]
            if prefix_sum == k:
                max_length = max(max_length, i + 1)
            if prefix_sum - k in prefix_sum_map:
                max_length = max(max_length, i - prefix_sum_map[prefix_sum - k])
            if prefix_sum not in prefix_sum_map:
                prefix_sum_map[prefix_sum] = i
        return max_length
