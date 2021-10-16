class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 0:
            return []
        parenthesis_queue = [('(', 1)]
        result = []
        while len(parenthesis_queue) > 0:
            string, left_count = parenthesis_queue.pop(0)
            if len(string) >= 2 * n:
                result.append(string)
            else:
                if left_count <= len(string) // 2:
                    parenthesis_queue.append((string + '(', left_count + 1))
                elif left_count >= n:
                    parenthesis_queue.append((string + ')', left_count))
                else:
                    parenthesis_queue.append((string + '(', left_count + 1))
                    parenthesis_queue.append((string + ')', left_count))
        return result
