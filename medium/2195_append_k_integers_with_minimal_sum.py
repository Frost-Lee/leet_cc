import heapq

class Solution:
    def minimalKSum(self, nums: List[int], k: int) -> int:
        heapq.heapify(nums)
        current_integer = 1
        result = 0
        while k > 0 and len(nums) > 0:
            min_integer = heapq.heappop(nums)
            if min_integer <= current_integer:
                current_integer = max(1, min_integer + 1)
            else:
                added_count = min(min_integer - current_integer, k)
                result += (2 * current_integer + added_count - 1) * added_count // 2
                k -= added_count
                current_integer = min_integer + 1
        if k > 0:
            result += (2 * current_integer + k - 1) * k // 2
        return result
