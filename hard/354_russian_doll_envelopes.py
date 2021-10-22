class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        envelopes_widths = [*map(lambda x: x[1], sorted(envelopes, key=lambda x: (x[0], -x[1])))]
        ascending_widths = []
        for width in envelopes_widths:
            insertion_index = bisect.bisect_left(ascending_widths, width)
            if insertion_index >= len(ascending_widths):
                ascending_widths.append(width)
            else:
                ascending_widths[insertion_index] = width
        return len(ascending_widths)
