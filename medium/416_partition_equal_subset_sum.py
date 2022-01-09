class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        half_sum = sum(nums) / 2
        if not half_sum.is_integer():
            return False
        half_sum = int(half_sum)
        dp = [[False for _ in range(half_sum + 1)] for _ in range(2)]
        for i in range(half_sum, -1, -1):
            if nums[- 1] == i:
                dp[(len(nums) - 1) % 2][i] = True
        for i in range(len(nums) - 2, -1, -1):
            for j in range(half_sum + 1):
                if j - nums[i] > 0:
                    dp[i % 2][j] = dp[(i + 1) % 2][j] or dp[(i + 1) % 2][j - nums[i]]
                else:
                    dp[i % 2][j] = dp[(i + 1) % 2][j]
        return dp[0][half_sum]
