class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefix_sum, prefix_sum_dict = 0, {0 : 1}
        sublist_sum = 0
        for num in nums:
            prefix_sum += num
            if prefix_sum - k in prefix_sum_dict:
                sublist_sum += prefix_sum_dict[prefix_sum - k]
            if prefix_sum in prefix_sum_dict:
                prefix_sum_dict[prefix_sum] += 1
            else:
                prefix_sum_dict[prefix_sum] = 1
        return sublist_sum
