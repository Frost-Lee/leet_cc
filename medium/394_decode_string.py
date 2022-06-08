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
        operator_stack, operand_stack = deque(), deque()
        is_previous_left_bracket = False
        def append_add():
            nonlocal operator_stack, operand_stack
            while len(operator_stack) > 0 and (operator_stack[-1] == '*' or operator_stack[-1] == '+'):
                operand_stack.append(operator_stack.pop())
            operator_stack.append('+')
        def append_multiply():
            nonlocal operator_stack, operand_stack
            while len(operator_stack) > 0 and operator_stack[-1] == '*':
                operand_stack.append(operator_stack.pop())
            operator_stack.append('*')
        for element in parse_element(s):
            if isinstance(element, int):
                if not is_previous_left_bracket:
                    append_add()
                is_previous_left_bracket = False
                operand_stack.append(element)
                append_multiply()
            elif element == '[':
                is_previous_left_bracket = True
                operator_stack.append(element)
            elif element == ']':
                is_previous_left_bracket = False
                while operator_stack[-1] != '[':
                    operand_stack.append(operator_stack.pop())
                operator_stack.pop()
            elif isinstance(element, str):
                if not is_previous_left_bracket:
                    append_add()
                is_previous_left_bracket = False
                operand_stack.append(element)
        while len(operator_stack) > 0:
            operand_stack.append(operator_stack.pop())
        calculation_stack = deque([''])
        while len(operand_stack) > 0:
            element = operand_stack.popleft()
            if element == '+':
                right = calculation_stack.pop()
                left = calculation_stack.pop()
                calculation_stack.append(left + right)
            elif element == '*':
                target_string = calculation_stack.pop()
                multiplier = calculation_stack.pop()
                calculation_stack.append(multiplier * target_string)
            else:
                calculation_stack.append(element)
        return calculation_stack[0]
