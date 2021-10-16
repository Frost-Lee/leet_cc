class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        subsets = [[]]
        previous_element, previous_subset_length = None, None
        insertion_start_index = 0
        nums = sorted(nums)
        while len(nums) > 0:
            new_element = nums.pop()
            if new_element == previous_element:
                insertion_start_index = previous_subset_length
            elif new_element != previous_element:
                insertion_start_index = 0
            previous_element = new_element
            previous_subset_length = len(subsets)
            subsets += [subset + [new_element] for subset in subsets[insertion_start_index:]]
        return subsets
