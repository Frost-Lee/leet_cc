class Solution:
    def frequencySort(self, s: str) -> str:
        counter = Counter(s)
        unique_letters = sorted([*counter.keys()], key=lambda x: counter[x], reverse=True)
        result = ''
        for letter in unique_letters:
            result += letter * counter[letter]
        return result
