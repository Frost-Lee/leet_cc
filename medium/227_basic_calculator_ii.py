class Solution:
    def calculate(self, s: str) -> int:
        def get_elements(string):
            string = string.replace(' ', '')
            while len(string) > 0:
                if ord('0') <= ord(string[0]) <= ord('9'):
                    integer = 0
                    while len(string) > 0 and ord('0') <= ord(string[0]) <= ord('9'):
                        integer = 10 * integer + ord(string[0]) - ord('0')
                        string = string[1:]
                    yield integer
                else:
                    yield string[0]
                    string = string[1:]
        operation = '+'
        result, last_number = 0, 0
        for element in get_elements(s):
            if isinstance(element, int):
                if operation == '+':
                    result += last_number
                    last_number = element
                elif operation == '-':
                    result += last_number
                    last_number = -element
                elif operation == '*':
                    last_number = last_number * element
                elif operation == '/':
                    operand = last_number
                    last_number = abs(operand) // element * (1 if operand >= 0 else -1)
            elif isinstance(element, str):
                operation = element
        result += last_number
        return result
