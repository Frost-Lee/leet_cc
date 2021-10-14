class Solution:
    def permute_recursive(self, nums, start_index, result_container):
        if start_index == len(nums) - 1:
            result_container.append(copy.deepcopy(nums))
            return
        seen_numbers = set()
        for i in range(start_index, len(nums)):
            if nums[i] not in seen_numbers:
                nums[start_index], nums[i] = nums[i], nums[start_index]
                self.permute_recursive(nums, start_index + 1, result_container)
                nums[start_index], nums[i] = nums[i], nums[start_index]
                seen_numbers.add(nums[i])

    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        permutations = []
        self.permute_recursive(nums, 0, permutations)
        return permutations
