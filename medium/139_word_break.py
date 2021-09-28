class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        word_set = set(wordDict)
        dp_array = [False for _ in range(len(s) + 1)]
        dp_array[0] = True
        for i in range(1, len(s) + 1):
            for j in range(i):
                if dp_array[j] and s[j:i] in word_set:
                    dp_array[i] = True
                    break
        return dp_array[-1]
