import copy

class Solution:
    def permute_recursive(self, nums, start_index, result_container):
        if start_index == len(nums) - 1:
            result_container.append(copy.deepcopy(nums))
            return
        for i in range(start_index, len(nums)):
            nums[start_index], nums[i] = nums[i], nums[start_index]
            self.permute_recursive(nums, start_index + 1, result_container)
            nums[start_index], nums[i] = nums[i], nums[start_index]

    def permute(self, nums: List[int]) -> List[List[int]]:
        permutations = []
        self.permute_recursive(nums, 0, permutations)
        return permutations
