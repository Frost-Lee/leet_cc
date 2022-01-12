class Solution:
    def __init__(self):
        self.dp_map = {}

    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        if len(s) == 0:
            return ['']
        result = set()
        if s in self.dp_map:
            result = list(self.dp_map[s])
        else:
            for word in wordDict:
                if s[:len(word)] == word:
                    for subresult in self.wordBreak(s[len(word):], wordDict):
                        result.add(' '.join([word, subresult]).strip())
            self.dp_map[s] = result
        return list(result)
