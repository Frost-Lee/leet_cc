class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        if len(arr) == 0:
            return -1
        dp = [len(arr) + 1 for _ in range(len(arr))]
        min_subarray_length_sum = len(arr) + 1
        start, end, window_sum = 0, 0, arr[0]
        while end < len(arr):
            if window_sum == target:
                if end > 0:
                    dp[end] = min(dp[end - 1], end - start + 1)
                else:
                    dp[end] = end - start + 1
                if start > 0:
                    min_subarray_length_sum = min(min_subarray_length_sum, end - start + 1 + dp[start - 1])
                end += 1
                if end < len(arr):
                    window_sum += arr[end]

            elif window_sum < target:
                if end > 0:
                    dp[end] = dp[end - 1]
                end += 1
                if end < len(arr):
                    window_sum += arr[end]
            else:
                window_sum -= arr[start]
                start += 1
        return min_subarray_length_sum if min_subarray_length_sum <= len(arr) else -1
