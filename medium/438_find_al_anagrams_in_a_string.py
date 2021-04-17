class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        window_start, p_counter = 0, Counter(p)
        target_starts = []
        window_counter, difference_count = None, None
        for i in range(len(s) - len(p) + 1):
            if window_counter is not None:
                assert i != 0
                old_char, new_char = s[i - 1], s[i + len(p) - 1]
                if window_counter[old_char] == p_counter[old_char] + 1:
                    difference_count -= 1
                elif window_counter[old_char] == p_counter[old_char]:
                    difference_count += 1
                window_counter[old_char] -= 1
                if window_counter[new_char] == p_counter[new_char] - 1:
                    difference_count -= 1
                elif window_counter[new_char] == p_counter[new_char]:
                    difference_count += 1
                window_counter[new_char] += 1
            else:
                window_counter = Counter(s[:len(p)])
                difference_count = 0
                for key in set([*p_counter.keys()] + [*window_counter.keys()]):
                    if window_counter[key] != p_counter[key]:
                        difference_count += 1
            if difference_count == 0:
                target_starts.append(i)
        return target_starts
