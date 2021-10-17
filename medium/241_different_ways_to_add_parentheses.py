class Solution:
    def different_compute_recursive(self, elements):
        if len(elements) == 1:
            return [int(elements[0])]
        results = []
        for index, element in enumerate(elements):
            if element.isdigit():
                pass
            else:
                left_results = self.different_compute_recursive(elements[:index])
                right_results = self.different_compute_recursive(elements[index + 1:])
                for left in left_results:
                    for right in right_results:
                        if element == '+':
                            results.append(left + right)
                        elif element == '-':
                            results.append(left - right)
                        elif element == '*':
                            results.append(left * right)
        return results

    def diffWaysToCompute(self, expression: str) -> List[int]:
        elements = []
        for i in range(len(expression)):
            if expression[i].isdigit():
                if len(elements) > 0 and elements[-1].isdigit():
                    elements[-1] += expression[i]
                else:
                    elements.append(expression[i])
            else:
                elements.append(expression[i])
        return self.different_compute_recursive(elements)
