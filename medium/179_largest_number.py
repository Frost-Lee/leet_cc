import functools

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        nums = [*map(str, nums)]
        def compare(x, y):
            return 1 if x + y < y + x else -1
        return str(int(''.join(sorted(nums, key=functools.cmp_to_key(compare)))))
