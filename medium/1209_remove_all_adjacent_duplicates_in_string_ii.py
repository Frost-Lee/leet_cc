import collections

class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        char_stack, count_stack = collections.deque(), collections.deque()
        for i in range(len(s)):
            if len(char_stack) > 0 and char_stack[-1] == s[i]:
                count_stack.append(count_stack[-1] + 1)
            else:
                count_stack.append(1)
            char_stack.append(s[i])
            if count_stack[-1] == k:
                for _ in range(k):
                    char_stack.pop()
                    count_stack.pop()
        return ''.join(char_stack)
