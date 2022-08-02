class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        multiplier = 1
        result = 0
        for i in range(len(nums)):
            if len(nums) - 1 - i < i:
                break
            result = (result + multiplier * nums[i]) % 10
            if len(nums) - 1 - i == i:
                break
            result = (result + multiplier * nums[len(nums) - 1 - i]) % 10
            multiplier *= len(nums) - i - 1
            multiplier //= i + 1
        return result
