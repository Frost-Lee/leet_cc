class Solution:
    def validWordAbbreviation(self, word: str, abbr: str) -> bool:
        has_leading_zero = False
        def parse_element(string):
            nonlocal has_leading_zero
            index = 0
            while index < len(string):
                if ord('a') <= ord(string[index]) <= ord('z'):
                    yield string[index]
                    index += 1
                elif ord('0') <= ord(string[index]) <= ord('9'):
                    number = 0
                    if string[index] == '0':
                        has_leading_zero = True
                    while index < len(string) and ord('0') <= ord(string[index]) <= ord('9'):
                        number = number * 10 + int(string[index])
                        index += 1
                    yield number
        word_index = 0
        for element in parse_element(abbr):
            if has_leading_zero:
                return False
            if isinstance(element, str):
                if word_index >= len(word) or element != word[word_index]:
                    return False
                word_index += 1
            elif isinstance(element, int):
                if element == 0:
                    return False
                word_index += element
        return word_index == len(word)
