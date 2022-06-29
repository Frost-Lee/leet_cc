class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        monotonic_stack = []
        for i in range(len(num)):
            while k > 0 and len(monotonic_stack) > 0 and num[i] < monotonic_stack[-1]:
                monotonic_stack.pop()
                k -= 1
            monotonic_stack.append(num[i])
        if k > 0:
            monotonic_stack = monotonic_stack[:-k]
        return str(int(''.join(monotonic_stack))) if len(monotonic_stack) > 0 else "0"
