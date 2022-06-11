import collections

class WordDistance:
    def __init__(self, wordsDict: List[str]):
        self.word_index_map = collections.defaultdict(list)
        for index, word in enumerate(wordsDict):
            self.word_index_map[word].append(index)

    def shortest(self, word1: str, word2: str) -> int:
        assert word1 in self.word_index_map
        assert word2 in self.word_index_map
        index_1, index_2 = 0, 0
        min_distance = abs(self.word_index_map[word1][0] - self.word_index_map[word2][0])
        while 0 <= index_1 < len(self.word_index_map[word1]) and 0 <= index_2 < len(self.word_index_map[word2]):
            min_distance = min(min_distance, abs(self.word_index_map[word1][index_1] - self.word_index_map[word2][index_2]))
            if self.word_index_map[word1][index_1] > self.word_index_map[word2][index_2]:
                index_2 += 1
            else:
                index_1 += 1
        return min_distance
