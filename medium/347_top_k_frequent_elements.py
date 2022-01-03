import random

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counter = Counter(nums)
        unique_nums = list(counter.keys())
        def partition(left, right):
            pivot_index = random.randint(left, right)
            unique_nums[right], unique_nums[pivot_index] = unique_nums[pivot_index], unique_nums[right]
            pivot_index = right
            cursor_index = left - 1
            for i in range(left, right):
                if counter[unique_nums[i]] < counter[unique_nums[pivot_index]]:
                    cursor_index += 1
                    unique_nums[cursor_index], unique_nums[i] = unique_nums[i], unique_nums[cursor_index]
            cursor_index += 1
            unique_nums[cursor_index], unique_nums[pivot_index] = unique_nums[pivot_index], unique_nums[cursor_index]
            return cursor_index
        def quick_select(left, right, k):
            pivot_index = partition(left, right)
            if k == pivot_index - left:
                return
            elif k < pivot_index - left:
                quick_select(left, pivot_index - 1, k)
            elif k > pivot_index - left:
                quick_select(pivot_index + 1, right, k - (pivot_index - left + 1))
        quick_select(0, len(unique_nums) - 1, len(unique_nums) - k)
        return unique_nums[len(unique_nums) - k:]
