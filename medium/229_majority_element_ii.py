class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        nums_dict = {}
        for num in nums:
            if num in nums_dict:
                nums_dict[num] += 1
            else:
                nums_dict[num] = 1
        return [key for key, value in nums_dict.items() if value > len(nums) / 3]
