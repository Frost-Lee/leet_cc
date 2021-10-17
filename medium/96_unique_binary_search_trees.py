class Solution:
    def numTrees(self, n: int) -> int:
        dp = [1]
        for i in range(2, n + 1):
            dp.append(0)
            for j in range(i):
                left_count, right_count = j, i - j - 1
                print(left_count, right_count)
                if left_count == 0:
                    dp[-1] += dp[right_count - 1]
                elif right_count == 0:
                    dp[-1] += dp[left_count - 1]
                else:
                    dp[-1] += dp[left_count - 1] * dp[right_count - 1]
        return dp[n - 1]
