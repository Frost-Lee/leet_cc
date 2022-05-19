from collections import deque

class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        parentheses_stack = deque()
        removal_indices = set()
        for index, char in enumerate(s):
            if char == '(':
                parentheses_stack.append(('(', index))
            elif char == ')':
                if len(parentheses_stack) <= 0:
                    removal_indices.add(index)
                else:
                    parentheses_stack.pop()
        for _, index in parentheses_stack:
            removal_indices.add(index)
        result_string = ''
        for index, char in enumerate(s):
            if index not in removal_indices:
                result_string += char
        return result_string
