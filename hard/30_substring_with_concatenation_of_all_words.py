class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        results = []
        if len(words) == 0 or len(words[0]) == 0:
            return []
        word_length = len(words[0])
        word_counter = Counter(words)
        for i in range(len(s) - len(words) * word_length + 1):
            s_counter = Counter()
            for j in range(len(words)):
                new_word = s[i + j * word_length : i + j * word_length + word_length]
                s_counter[new_word] += 1
                if s_counter[new_word] > word_counter[new_word]:
                    break
                if j == len(words) - 1:
                    results.append(i)
        return results
