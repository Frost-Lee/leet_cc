class Solution:
    def minimumHealth(self, damage: List[int], armor: int) -> int:
        armor_deduction = min(armor, max(damage))
        return sum(damage) - armor_deduction + 1
