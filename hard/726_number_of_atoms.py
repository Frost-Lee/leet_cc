class Solution:
    def parse_element(self, formula):
        if len(formula) == 0 or not (ord('A') <= ord(formula[0]) <= ord('Z')):
            return None
        element = formula[0]
        formula = formula[1:]
        while len(formula) > 0 and ord('a') <= ord(formula[0]) <= ord('z'):
            element += formula[0]
            formula = formula[1:]
        return element, formula

    def parse_count(self, formula):
        count_string = ''
        while len(formula) > 0 and ord('0') <= ord(formula[0]) <= ord('9'):
            count_string += formula[0]
            formula = formula[1:]
        if len(count_string) == 0:
            return 1, formula
        else:
            return int(count_string), formula

    def parse(self, formula):
        if format is None or len(formula) == 0:
            return None
        if formula[0] == '(':
            return 0, formula[1:]
        elif formula[0] == ')':
            return self.parse_count(formula[1:])
        else:
            element, formula = self.parse_element(formula)
            count, formula = self.parse_count(formula)
            return (element, count), formula

    def countOfAtoms(self, formula: str) -> str:
        counter_stack = [Counter()]
        while len(formula) > 0:
            parse_result, formula = self.parse(formula)
            if isinstance(parse_result, tuple):
                counter_stack[-1][parse_result[0]] += parse_result[1]
            else:
                if parse_result == 0:
                    counter_stack.append(Counter())
                else:
                    assert len(counter_stack) > 1
                    tail_counter = counter_stack.pop()
                    for key, value in tail_counter.items():
                        counter_stack[-1][key] += value * parse_result
        assert len(counter_stack) == 1
        flat_counter = sorted([(key, value) for key, value in counter_stack[0].items()], key=lambda x: x[0])
        result_string = ''
        for key, value in flat_counter:
            result_string += key
            if value > 1:
                result_string += str(value)
        return result_string