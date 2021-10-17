class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        ordered_array = []
        for num in nums:
            insertion_index = bisect.bisect_left(ordered_array, num)
            if insertion_index >= len(ordered_array):
                ordered_array.append(num)
            else:
                ordered_array[insertion_index] = num
        return len(ordered_array)
