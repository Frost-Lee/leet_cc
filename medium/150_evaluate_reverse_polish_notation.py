class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        element_stack = []
        for token in tokens:
            if token in '+-*/':
                num_2, num_1 = element_stack.pop(), element_stack.pop()
                if token == '+':
                    element_stack.append(num_1 + num_2)
                elif token == '-':
                    element_stack.append(num_1 - num_2)
                elif token == '*':
                    element_stack.append(num_1 * num_2)
                elif token == '/':
                    element_stack.append(int(num_1 / num_2))
            else:
                element_stack.append(int(token))
        return element_stack[0]
