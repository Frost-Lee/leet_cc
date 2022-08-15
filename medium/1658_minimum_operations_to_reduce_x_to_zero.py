class Solution:
    def minOperations(self, nums, x: int) -> int:
        target_sum = sum(nums) - x
        if target_sum == 0:
            return len(nums)
        left = 0
        window_sum = 0
        max_subarray_length = -1
        for right in range(len(nums)):
            window_sum += nums[right]
            while window_sum > target_sum and left <= right:
                window_sum -= nums[left]
                left += 1
            if window_sum == target_sum:
                max_subarray_length = max(max_subarray_length, right - left + 1)
        return len(nums) - max_subarray_length if max_subarray_length > 0 else -1
