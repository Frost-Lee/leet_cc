import collections

class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        words_1_counter_map = {word : collections.Counter(word) for word in words1}
        words_2_counter_map = {word : collections.Counter(word) for word in words2}
        universal_counter = collections.Counter()
        for counter in words_2_counter_map.values():
            for key, count in counter.items():
                universal_counter[key] = max(universal_counter[key], count)
        result = []
        for word, counter in words_1_counter_map.items():
            is_universal = True
            for key, count in universal_counter.items():
                if counter[key] < count:
                    is_universal = False
                    break
            if is_universal:
                result.append(word)
        return result
