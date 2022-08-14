import collections

class Solution:
    def calculate(self, s: str) -> int:
        def next_element(expression_string):
            index = 0
            while index < len(expression_string):
                if expression_string[index].isdigit():
                    parsed_number = int(expression_string[index])
                    index += 1
                    while index < len(expression_string) and expression_string[index].isdigit():
                        parsed_number = parsed_number * 10 + int(expression_string[index])
                        index += 1
                    yield parsed_number
                else:
                    yield expression_string[index]
                    index += 1
        def operator_priority(operator):
            if operator == '+' or operator == '-':
                return 1
            elif operator == '*' or operator == '/':
                return 2
            return 0
        def evaluate(left, right, operator):
            if operator == '+':
                return left + right
            elif operator == '-':
                return left - right
            elif operator == '*':
                return left * right
            elif operator == '/':
                return int(left / right)
            else:
                return 0
        operation_stack, operation_list = collections.deque(), collections.deque()
        for element in next_element(s):
            if isinstance(element, int):
                operation_list.append(element)
            elif element == '(':
                operation_stack.append(element)
            elif element == ')':
                while operation_stack[-1] != '(':
                    operation_list.append(operation_stack.pop())
                operation_stack.pop()
            else:
                while len(operation_stack) > 0 and operator_priority(operation_stack[-1]) >= operator_priority(element):
                    operation_list.append(operation_stack.pop())
                operation_stack.append(element)
        while len(operation_stack) > 0:
            operation_list.append(operation_stack.pop())
        evaluation_stack = collections.deque()
        for element in operation_list:
            if isinstance(element, int):
                evaluation_stack.append(element)
            else:
                right_operand = evaluation_stack.pop()
                left_operand = evaluation_stack.pop()
                evaluation_stack.append(evaluate(left_operand, right_operand, element))
        return evaluation_stack[0]
