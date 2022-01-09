class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        num_sum = sum(nums)
        dp = [[0 for _ in range(num_sum * 2 + 1)] for _ in range(2)]
        for i in range(num_sum * 2 + 1):
            if nums[0] == i - num_sum:
                dp[0][i] += 1
            if -nums[0] == i - num_sum:
                dp[0][i] += 1
        for i in range(1, len(nums)):
            for j in range(num_sum * 2 + 1):
                if j - nums[i] >= 0:
                    dp[i % 2][j] += dp[(i - 1) % 2][j - nums[i]]
                if j + nums[i] < num_sum * 2 + 1:
                    dp[i % 2][j] += dp[(i - 1) % 2][j + nums[i]]
            dp[(i - 1) % 2] = [0 for _ in range(num_sum * 2 + 1)]
        if target + num_sum >= 2 * num_sum + 1:
            return 0
        else:
            return dp[(len(nums) - 1) % 2][target + num_sum]
