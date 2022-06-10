import collections

class Solution:
    def decodeString(self, s: str) -> str:
        def parse_element(string):
            index = 0
            while index < len(string):
                if ord('a') <= ord(string[index]) <= ord('z'):
                    yield string[index]
                    index += 1
                elif string[index] == '[' or string[index] == ']':
                    yield string[index]
                    index += 1
                elif ord('0') <= ord(string[index]) <= ord('9'):
                    number = 0
                    while ord('0') <= ord(string[index]) <= ord('9'):
                        number = number * 10 + int(string[index])
                        index += 1
                    yield number
        multiplier_stack, string_stack = collections.deque(), collections.deque()
        current_multiplier, current_string = 0, ''
        for element in parse_element(s):
            if element == '[':
                multiplier_stack.append(current_multiplier)
                string_stack.append(current_string)
                current_string = ''
            elif element == ']':
                current_string = string_stack.pop() + multiplier_stack.pop() * current_string
            elif isinstance(element, int):
                current_multiplier = element
            elif isinstance(element, str):
                current_string += element
        return current_string
