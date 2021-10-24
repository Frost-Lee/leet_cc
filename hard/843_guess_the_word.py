class Solution:
    def findSecretWord(self, wordlist: List[str], master: 'Master') -> None:
        def match_count(word_1, word_2):
            return sum(i == j for i, j in zip(word_1, word_2))
        matched_count = 0
        while matched_count < 6:
            positional_char_count = [Counter(word[i] for word in wordlist) for i in range(6)]
            non_unique_word = max(wordlist, key=lambda x: sum([positional_char_count[i][x[i]] for i in range(6)]))
            matched_count = master.guess(non_unique_word)
            wordlist = [*filter(lambda x: match_count(x, non_unique_word) == matched_count, wordlist)]
