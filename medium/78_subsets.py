class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        subsets = [[]]
        while len(nums) > 0:
            new_element = nums.pop()
            subsets += [subset + [new_element] for subset in subsets]
        return subsets
