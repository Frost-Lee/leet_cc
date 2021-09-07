class Solution:
    def boldWords(self, words: List[str], s: str) -> str:
        match_mask = [False for _ in range(len(s))]
        for word in words:
            index_shift = 0
            while word in s[index_shift:]:
                start_index = s[index_shift:].index(word)
                for i in range(len(word)):
                    match_mask[index_shift + start_index + i] = True
                index_shift += (start_index + 1)
        current_state = False
        result_string = ''
        for i in range(len(match_mask)):
            if match_mask[i] != current_state:
                result_string += '<{}b>'.format('' if current_state == False else '/')
                current_state = match_mask[i]
            result_string += s[i]
        if current_state:
            result_string += '</b>'
        return result_string
