class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        count, count_dict = 0, {0: -1}
        max_len = 0
        for index, num in enumerate(nums):
            count += (1 if num == 1 else -1)
            if count not in count_dict:
                count_dict[count] = index
            else:
                max_len = max(max_len, index - count_dict[count])
        return max_len
