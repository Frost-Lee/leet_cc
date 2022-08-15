class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        sorted_satisfaction = sorted(satisfaction)
        index = len(sorted_satisfaction) - 1
        result, current_sum = 0, 0
        while index >= 0 and sorted_satisfaction[index] + current_sum > 0:
            current_sum = current_sum + sorted_satisfaction[index]
            result += current_sum
            index -= 1
        return result
